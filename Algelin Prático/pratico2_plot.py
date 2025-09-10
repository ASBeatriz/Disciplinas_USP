import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Vetores bases do plano
u = np.array([1, 0, 1])
v = np.array([0, 1, 1])

# Gera pontos os coeficientes das combinações lineares, variando de -2 a 2
s = np.linspace(-2, 2, 20)  # coeficientes de u
t = np.linspace(-2, 2, 20)  # coeficientes de v
S, T = np.meshgrid(s, t)

# Gera as combinações lineares: cada ponto do plano é P = s*u + t*v
X = S*u[0] + T*v[0]
Y = S*u[1] + T*v[1]
Z = S*u[2] + T*v[2]

# Plot
fig = plt.figure(figsize=(10,8))
ax = fig.add_subplot(111, projection='3d')

# Gera a superfície do plano    
ax.plot_surface(X, Y, Z, alpha=0.5, color="cyan")
# ax.plot_wireframe(X, Y, Z, color="cyan")

# Vetor w
alpha = 0.7
beta = 0.3
w_x = u[0]*alpha + v[0]*beta
w_y = u[1]*alpha + v[1]*beta
w_z = u[2]*alpha + v[2]*beta
w = (w_x, w_y, w_z)

# Gera os vetores u, v e w
ax.quiver(0, 0, 0, u[0], u[1], u[2], color="red", linewidth=2, label="u")
ax.quiver(0, 0, 0, v[0], v[1], v[2], color="blue", linewidth=2, label="v")
ax.quiver(0, 0, 0, w[0], w[1], w[2], color="green", linewidth=2, label="w")

# Ajusta limites e rótulos
ax.set_xlim([-2, 2])
ax.set_ylim([-2, 2])
ax.set_zlim([-2, 2])
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")
ax.legend()

plt.show()