import numpy as np
import matplotlib.pyplot as plt

# Discretização dos pontos de C
t = np.linspace(0, 2*np.pi, 400)       # 400 valores de ângulos entre 0 e 2 pi
C = np.vstack((np.cos(t), np.sin(t)))  # calcula pontos (x,y) na circunferência e tranforma em uma matriz

# Matriz da transformação linear
A = np.array([[2, 1],
              [1, 2]])

# Aplica a transformação linear
C_transf = A @ C

# Plot
plt.figure(figsize=(8,8))
plt.plot(C[0, :], C[1, :], 'b')                 # círculo
plt.plot(C_transf[0, :], C_transf[1, :], 'r')   # círculo após tranformação

# Eixos
plt.axhline(0, color='black', linewidth=0.5)
plt.axvline(0, color='black', linewidth=0.5)

plt.title("Transformação Linear da Circunferência")
plt.show()
