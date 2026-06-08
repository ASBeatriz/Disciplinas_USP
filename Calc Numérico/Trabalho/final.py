import os
import cv2
import numpy as np
import matplotlib.pyplot as plt
from jacobi import solve_svd_jacobi

video_path = 'video.mp4'

output_dir = "results"
svd_dir = "SVDs"
video_name = os.path.splitext(os.path.basename(video_path))[0]
svd_file = os.path.join(svd_dir, f"{video_name}_svd_gray.npz")

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


def get_gray_frames():
    cap = cv2.VideoCapture(f"{video_name}_gray.mp4")

    if not cap.isOpened():
        print("Erro ao abrir o vídeo em escala de cinza.")
        return

    reslx = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
    resly = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

    print(f"Dimensões: {reslx}x{resly}")

    gray_frames = []

    print("Lendo vídeo em escala de cinza...")

    while True:

        ret, frame = cap.read()

        if not ret:
            break

        if len(frame.shape) == 3:
            frame = frame[:, :, 0]

        gray_frames.append(
            frame.flatten()
        )

    cap.release()
    return gray_frames, reslx, resly


def get_SVD(svd_file, video_path, force_recompute=False):

    # Verifica se o SVD já foi calculado anteriormente para evitar recálculo
    if os.path.exists(svd_file) and not force_recompute:

        print(f"Carregando SVD salva: {svd_file}")

        data = np.load(svd_file)

        U = data["U"]
        S = data["S"]
        VT = data["VT"]
        A = data["A"]

        reslx = int(data["reslx"])
        resly = int(data["resly"])

        return A, U, S, VT, reslx, resly

    else:

        # Busca o vídeo gerado após o pré-processamento
        gray_frames, reslx, resly = get_gray_frames()

        A = np.array(gray_frames).T.astype(np.float64)

        print(f"Matriz A: {A.shape}")

        print("Calculando SVD...")

        U, S, VT = solve_svd_jacobi(A)

        np.savez_compressed(
            svd_file,
            U=U,
            S=S,
            VT=VT,
            A=A,
            reslx=reslx,
            resly=resly
        )

        print(f"SVD salva em {svd_file}")

        return A, U, S, VT, reslx, resly


def create_comparison_frame(frame, background_uint8, foreground_gray):

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

    return np.hstack([
        original_panel,
        background_panel,
        movement_panel
    ])


def generate_videos(A, U, S, VT, reslx, resly, video_path, k, threshold=30):

    print(f"Reconstruindo fundo com k={k}")

    L = (U[:, :k] * S[:k]) @ VT[:k, :]
    foreground_matrix = np.abs(A - L)



    cap = cv2.VideoCapture(video_path)
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')

    # Arquivos de saída

    output_rgb = os.path.join(output_dir, f"{video_name}_foreground_k{k}.mp4")
    output_gray = os.path.join(output_dir, f"{video_name}_foreground_gray_k{k}.mp4")
    output_comparison = os.path.join(output_dir, f"{video_name}_comparison_k{k}.mp4")

    # Escritores

    out_rgb = cv2.VideoWriter(output_rgb, fourcc, 20.0, (reslx, resly), isColor=True)
    out_gray = cv2.VideoWriter(output_gray, fourcc, 20.0, (reslx, resly), isColor=False)
    out_comparison = cv2.VideoWriter(output_comparison, fourcc, 20.0, (reslx * 3, resly), isColor=True)

    print("Gerando vídeos...")

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

        # ==========================================
        # Movimento (S)
        # ==========================================

        foreground = foreground_matrix[:, frame_idx]
        foreground = foreground.reshape((resly, reslx))

        foreground_gray = cv2.normalize(
            foreground,
            None,
            0,
            255,
            cv2.NORM_MINMAX
        ).astype(np.uint8)

        # salva vídeo cinza
        out_gray.write(foreground_gray)

        # ==========================================
        # Fundo (L)
        # ==========================================

        background = L[:, frame_idx]
        background = background.reshape(
            (resly, reslx)
        )

        background_uint8 = np.clip(
            background,
            0,
            255
        ).astype(np.uint8)

        # ==========================================
        # Máscara de movimento
        # ==========================================

        mask = np.zeros_like(
            foreground,
            dtype=np.uint8
        )

        mask[foreground > threshold] = 255

        kernel = np.ones(
            (3, 3),
            np.uint8
        )

        mask = cv2.morphologyEx(
            mask,
            cv2.MORPH_OPEN,
            kernel
        )

        # ==========================================
        # Movimento RGB
        # ==========================================

        foreground_rgb = cv2.bitwise_and(
            frame,
            frame,
            mask=mask
        )

        # salva vídeo com a máscara rgb
        out_rgb.write(foreground_rgb)


        # Cria o frame de comparação com os vídeos
        comparison = create_comparison_frame(
            frame,
            background_uint8,
            foreground_gray
        )

        # salva vídeo de comparação
        out_comparison.write(comparison)

        frame_idx += 1

    cap.release()

    out_rgb.release()
    out_gray.release()
    out_comparison.release()

    print("Vídeos gerados:")
    print(output_rgb)
    print(output_gray)
    print(output_comparison)

    plotar_decaimento(S, k)

def main():
    # Calcula o SVD
    A, U, S, VT, reslx, resly = get_SVD(svd_file, video_path, True)

    # Faz o isolamento do fundo e gera os vídeos para comparação
    generate_videos(A, U, S, VT, reslx, resly, video_path, k=5, threshold=30)


main()