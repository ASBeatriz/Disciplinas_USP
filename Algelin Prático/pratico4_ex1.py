import numpy as np
import matplotlib.pyplot as plt
import math

# Valores de T aplicados à base canônica do R²
T10 = lambda theta: np.array([math.cos(theta), math.sin(theta)])    # T(1,0) = (cosθ, senθ)
T01 = lambda theta: np.array([-math.sin(theta), math.cos(theta)])   # T(1,0) = (-senθ, cosθ)

# Cálculo de T
# T(x,y) = xT(1,0) + yT(0,1) = (xcosθ - ysenθ, xsenθ + ycosθ)

def T(theta, x, y):
    return x*T10(theta) + y*T01(theta)

# Matriz da transformação T
#   cosθ  -senθ    
#   senθ   cosθ

def matriz_T(theta):
    A = np.column_stack([T10(theta), T01(theta)])
    return A

theta = math.pi/2
print(f"Considerando θ = {theta}")

x, y = 1, 1
print(f"Valor de T({x},{y}): {T(theta, 1, 1)}")

print(f"Matriz de T:\n {np.round(matriz_T(theta), 2)}")


# Triângulo original (fechado)
tri_orig = np.array([[-1, 1],
                    [ 1, 1],
                    [ 0, 1],
                    [-1, 1]])
theta = math.pi/4
A = matriz_T(theta)

# Aplica T em todos os pontos do triângulo
tri_transf = np.array([T(theta, x, y) for x, y in tri_orig])

# Plotagem
plt.figure(figsize=(6,6))
plt.axhline(0, color="black", linewidth=0.5)
plt.axvline(0, color="black", linewidth=0.5)

plt.plot(tri_orig[:,0], tri_orig[:,1], 'bo-', label="Original")
plt.plot(tri_transf[:,0], tri_transf[:,1], 'ro-', label="Transformado")

plt.gca().set_aspect("equal", adjustable="box")
plt.legend()
plt.title("Transformação T aplicada ao triângulo")
plt.show()