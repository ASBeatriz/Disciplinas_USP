import sympy as sp

# Vetores do núcleo
k1 = sp.Matrix([1,1,1,1,1])
k2 = sp.Matrix([1,1,1,1,0])

# Vetores da imagem desejada
i1 = sp.Matrix([1,0,0])
i2 = sp.Matrix([0,1,0])
i3 = sp.Matrix([1,1,1])

# Matriz T desconhecida 3x5
T = sp.Matrix(sp.symbols('t0:15')).reshape(3,5)

# Equações geradas pelo núcleo (T*k1 = 0, T*k2 = 0)
eqs = list(T * k1) + list(T * k2)

# Seja e1, e2 e e3 os três primeiros vetores canônicos do R⁵, vamos usá-los para completar uma base em R⁵
# Definimos que T(e1) = i1, T(e2) = i2, T(e3) = i3
e1, e2, e3 = sp.eye(5)[:,0], sp.eye(5)[:,1], sp.eye(5)[:,2]
eqs += list(T * e1 - i1)
eqs += list(T * e2 - i2)
eqs += list(T * e3 - i3)

# Resolve o sistema
sol = sp.linsolve(eqs, *T)  
matriz_T = sp.Matrix(list(sol.args[0])).reshape(3,5)

print("Matriz de T =")
sp.pprint(matriz_T)


print("Teste:")
print("T * k1 =", matriz_T @ k1)  
print("T * k2 =", matriz_T @ k2)  
print("T * k2 =", matriz_T @ e1)  
print("T * k2 =", matriz_T @ e2)  
print("T * k2 =", matriz_T @ e3)  