import numpy as np
import cv2
import os

video_path = 'video.mp4'
video_name = os.path.splitext(os.path.basename(video_path))[0]

def convert_to_gray_simple(frame):
    # cada novo pixel vai ter como nova cor a media simples dos 3 canais de cor (BGR):
    #  (B + G + R) / 3
    gray =(frame[:, :, 0].astype(np.float32) + frame[:, :, 1].astype(np.float32) + frame[:, :, 2].astype(np.float32)) / 3
    
    return gray.astype(np.uint8)

# equivalente:
# def convert_to_gray_luminosity(frame):
#     return cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
def convert_to_gray_luminosity(frame):
    # frame em BGR: canal 0 = B, 1 = G, 2 = R
    gray = 0.114 * frame[:, :, 0].astype(np.float32) + 0.587 * frame[:, :, 1].astype(np.float32) + 0.299 * frame[:, :, 2].astype(np.float32)

    return gray.astype(np.uint8)

# equivalente:
# def resize_frame(frame, width, height):
#     return cv2.resize(frame, (width, height), interpolation=cv2.INTER_NEAREST)
def resize_frame(frame, width, height):
    h, w = frame.shape[0], frame.shape[1]

    resized = np.zeros((height, width, *frame.shape[2:]), dtype=frame.dtype)

    # percorre cada pixel do novo frame e mapeia para o pixel correspondente no frame original
    for row in range(height):
        for col in range(width):
            # coordenadas do pixel correspondente no frame original são calculadas usando 
            # a proporção entre as dimensões do novo frame e do frame original
            src_row = int(row * h / height)
            src_col = int(col * w / width)

            resized[row, col] = frame[src_row, src_col] 

    return resized

# le o video original e devolve uma lista de frames preprocessados:
# redimensionados (menos processamento) e em escala de cinza (uma unica matriz por frame)
def preprocess(cap, scale, save_intermediate=False):
    fps = cap.get(cv2.CAP_PROP_FPS)
    new_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH)) // scale
    new_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT)) // scale

    frames = []
    while True:
        ret, frame = cap.read() # frame eh uma numpy array de 3 dimensoes, com as 3 camadas de cor (BGR)
        if not ret:
            break

        frame = resize_frame(frame, new_width, new_height)
        frame = convert_to_gray_luminosity(frame)

        frames.append(frame)

    cap.release()
    return frames, fps

def save_video(video_path, frames, fps):
    height, width = frames[0].shape
    out = cv2.VideoWriter(video_path, cv2.VideoWriter_fourcc(*'mp4v'), fps, (width, height), isColor=False)
    for frame in frames:
        out.write(frame)
    out.release()


def main():
    cap = cv2.VideoCapture(video_path)
    frames, fps = preprocess(cap, scale=2)


    M = np.array(frames).T.astype(np.float64)

    save_video(f'{video_name}_gray.mp4', frames, fps)

main()