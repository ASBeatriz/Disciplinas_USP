import os
import cv2
import numpy as np
import matplotlib.pyplot as plt

output_dir = "results"
svd_dir = "SVDs"

os.makedirs(output_dir, exist_ok=True)
os.makedirs(svd_dir, exist_ok=True)


def plotar_decaimento(S, k):

    k_sum = np.sum(S[:k] ** 2)
    r_sum = np.sum(S ** 2)

    print(f"Variância acumulada ({k} componentes): {k_sum / r_sum:.4f}")

    figure, axes = plt.subplots(1, 2, figsize=(12, 5))

    plt.suptitle("Decaimento dos Valores Singulares")

    axes[0].set_title("Escala Linear")
    axes[0].plot(np.arange(len(S)), S)

    axes[1].set_title("Escala Logarítmica")
    axes[1].set_yscale('log')
    axes[1].plot(np.arange(len(S)), S)

    plt.tight_layout()
    plt.show()


def process_video_svd_rgb_mask(
    video_path,
    k=5,
    threshold=30,
    force_recompute=False
):

    video_name = os.path.splitext(os.path.basename(video_path))[0]

    svd_file = os.path.join(
        svd_dir,
        f"{video_name}_svd_gray.npz"
    )

    # =====================================================
    # CARREGA OU CALCULA SVD
    # =====================================================

    if os.path.exists(svd_file) and not force_recompute:

        print(f"Carregando SVD salva: {svd_file}")

        data = np.load(svd_file)

        U = data["U"]
        S = data["S"]
        VT = data["VT"]
        M = data["M"]

        reslx = int(data["reslx"])
        resly = int(data["resly"])

    else:

        cap = cv2.VideoCapture(video_path)

        if not cap.isOpened():
            print("Erro ao abrir o vídeo.")
            return

        width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
        height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

        print(f"Dimensões: {width}x{height}")

        # Reduza se a SVD estiver demorando muito
        # reslx, resly = width, height
        reslx, resly = width // 2, height // 2

        gray_frames = []

        print("Lendo vídeo para cálculo da SVD...")

        while True:

            ret, frame = cap.read()

            if not ret:
                break

            frame = cv2.resize(frame, (reslx, resly))

            gray = cv2.cvtColor(
                frame,
                cv2.COLOR_BGR2GRAY
            )

            gray_frames.append(
                gray.flatten()
            )

        cap.release()

        M = np.array(gray_frames).T.astype(np.float64)

        print(f"Matriz M: {M.shape}")

        print("Calculando SVD...")

        U, S, VT = np.linalg.svd(
            M,
            full_matrices=False
        )

        np.savez_compressed(
            svd_file,
            U=U,
            S=S,
            VT=VT,
            M=M,
            reslx=reslx,
            resly=resly
        )

        print(f"SVD salva em {svd_file}")

    # =====================================================
    # RECONSTRUÇÃO DO FUNDO
    # =====================================================

    print(f"Reconstruindo fundo com k={k}")

    L = (U[:, :k] * S[:k]) @ VT[:k, :]

    foreground_matrix = np.abs(M - L)

    # =====================================================
    # SEGUNDA LEITURA DO VÍDEO
    # =====================================================

    cap = cv2.VideoCapture(video_path)

    fourcc = cv2.VideoWriter_fourcc(*'mp4v')

    # -----------------------------------------------------
    # Movimento RGB
    # -----------------------------------------------------

    output_rgb = os.path.join(
        output_dir,
        f"{video_name}_foreground_k{k}.mp4"
    )

    out_rgb = cv2.VideoWriter(
        output_rgb,
        fourcc,
        20.0,
        (reslx, resly),
        isColor=True
    )

    # -----------------------------------------------------
    # Movimento em cinza
    # -----------------------------------------------------

    output_gray = os.path.join(
        output_dir,
        f"{video_name}_foreground_gray_k{k}.mp4"
    )

    out_gray = cv2.VideoWriter(
        output_gray,
        fourcc,
        20.0,
        (reslx, resly),
        isColor=False
    )

    # -----------------------------------------------------
    # Comparação lado a lado
    # -----------------------------------------------------

    output_comparison = os.path.join(
        output_dir,
        f"{video_name}_comparison_k{k}.mp4"
    )

    out_comparison = cv2.VideoWriter(
        output_comparison,
        fourcc,
        20.0,
        (reslx * 3, resly),
        isColor=True
    )

    print(f"Gerando {output_comparison}")

    frame_idx = 0

    while True:

        ret, frame = cap.read()

        if not ret:
            break

        if frame_idx >= foreground_matrix.shape[1]:
            break

        frame = cv2.resize(
            frame,
            (reslx, resly)
        )

        # =================================================
        # Movimento (S)
        # =================================================

        foreground = foreground_matrix[:, frame_idx]
        foreground = foreground.reshape(
            (resly, reslx)
        )

        foreground_gray = cv2.normalize(
            foreground,
            None,
            0,
            255,
            cv2.NORM_MINMAX
        ).astype(np.uint8)

        out_gray.write(
            foreground_gray
        )

        # =================================================
        # Fundo (L)
        # =================================================

        background = L[:, frame_idx]
        background = background.reshape(
            (resly, reslx)
        )

        background_uint8 = np.clip(
            background,
            0,
            255
        ).astype(np.uint8)

        # =================================================
        # Máscara
        # =================================================

        mask = np.zeros_like(
            foreground,
            dtype=np.uint8
        )

        mask[
            foreground > threshold
        ] = 255

        kernel = np.ones(
            (3, 3),
            np.uint8
        )

        mask = cv2.morphologyEx(
            mask,
            cv2.MORPH_OPEN,
            kernel
        )

        # =================================================
        # Movimento RGB
        # =================================================

        foreground_rgb = cv2.bitwise_and(
            frame,
            frame,
            mask=mask
        )

        out_rgb.write(
            foreground_rgb
        )

        # =================================================
        # Painel comparativo
        # =================================================

        original_panel = frame.copy()

        background_panel = cv2.cvtColor(
            background_uint8,
            cv2.COLOR_GRAY2BGR
        )

        movement_panel = cv2.cvtColor(
            foreground_gray,
            cv2.COLOR_GRAY2BGR
        )

        cv2.putText(
            original_panel,
            "Original",
            (10, 30),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (0, 255, 0),
            2
        )

        cv2.putText(
            background_panel,
            "Fundo (L)",
            (10, 30),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (0, 255, 0),
            2
        )

        cv2.putText(
            movement_panel,
            "Movimento (S)",
            (10, 30),
            cv2.FONT_HERSHEY_SIMPLEX,
            1,
            (0, 255, 0),
            2
        )

        comparison = np.hstack([
            original_panel,
            background_panel,
            movement_panel
        ])

        out_comparison.write(
            comparison
        )

        frame_idx += 1

    cap.release()

    out_rgb.release()
    out_gray.release()
    out_comparison.release()

    plotar_decaimento(S, k)

    print("Concluído!")
    print(f"Movimento RGB: {output_rgb}")
    print(f"Movimento Cinza: {output_gray}")
    print(f"Comparação: {output_comparison}")


process_video_svd_rgb_mask(
    "video.mp4",
    k=5,
    threshold=30,
    force_recompute=False
)