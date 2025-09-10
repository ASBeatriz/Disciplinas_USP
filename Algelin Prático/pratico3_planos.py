import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.patches as mpatches
import matplotlib.lines as mlines

# Vetores bases do plano U
u1 = np.array([0, 0, 1])
u2 = np.array([0, 1, 0])

# Vetores bases do plano V
v1 = np.array([0, 0, 1])
v2 = np.array([1, 0, 0])

# Normais dos planos
nU = np.cross(u1, u2)
nV = np.cross(v1, v2)

# Direção da reta de interseção (produto vetorial das normais)
d = np.cross(nU, nV)

# Pontos da reta de interseção
t = np.linspace(-2, 2, 20)  # coeficientes para multiplicar o vetor direção
Xr = t * d[0]
Yr = t * d[1]
Zr = t * d[2]

# Gera pontos os coeficientes das combinações lineares, variando de -2 a 2
s = np.linspace(-2, 2, 20)      # coeficientes de u1 e v1
t = np.linspace(-2, 2, 20)      # coeficientes de u2 e v2
S, T = np.meshgrid(s, t)

# Gera as combinações lineares do plano U
XU = S*u1[0] + T*u2[0]
YU = S*u1[1] + T*u2[1]
ZU = S*u1[2] + T*u2[2]

# Gera as combinações lineares do plano V
XV = S*v1[0] + T*v2[0]
YV = S*v1[1] + T*v2[1]
ZV = S*v1[2] + T*v2[2]

# Plot
fig = plt.figure(figsize=(10,8))
ax = fig.add_subplot(111, projection='3d')

# Gera as superfícies e a interseção
ax.plot_surface(XU, YU, ZU, alpha=0.5, color="cyan")
ax.plot_surface(XV, YV, ZV, alpha=0.5, color="pink", shade=False)
ax.plot(Xr, Yr, Zr, color="red", linewidth=3)

# Objetos para legenda
planoU_patch = mpatches.Patch(color='cyan', alpha=0.5, label='Plano U')
planoV_patch = mpatches.Patch(color='pink', alpha=0.5, label='Plano V')
intersec_line = mlines.Line2D([], [], color='red', linewidth=3, label='Interseção U∩V')

ax.legend(handles=[planoU_patch, planoV_patch, intersec_line])


# Ajusta limites e rótulos
ax.set_xlim([-2, 2])
ax.set_ylim([-2, 2])
ax.set_zlim([-2, 2])
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")

plt.show()