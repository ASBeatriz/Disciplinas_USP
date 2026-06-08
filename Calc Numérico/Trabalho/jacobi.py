import numpy as np

def jacobi_rotation(A, p, q):
    n = A.shape[0]
    U = np.eye(n)

    phi = (A[q, q] - A[p, p]) / (2 * A[p, q])
    
    if phi == 0:
        t = 1
    else:
        t = 1 / (phi + np.sign(phi) * np.sqrt(phi**2 + 1))

    c = 1 / np.sqrt(t**2 + 1)

    s = t * c

    U[p, p] = c
    U[q, q] = c
    U[p, q] = s
    U[q, p] = -s

    return U

def find_position(A):
    n = A.shape[0]
    mx = 0
    p, q = 0, 1
    for i in range(n):
        for j in range(i+1, n):
            if mx < np.abs(A[i][j]):
                mx = np.abs(A[i][j])
                p, q = i, j

    return p, q, mx

def solve_jacobi(A, tol=1e-10, max_iterations=100):
    # Inicializando k, número de iterações
    k = 0

    n = A.shape[0]
    V = np.eye(n)

    # Enquanto k não atingir o número de iterações definidas no parâmetro
    # o algoritmo continua
    while(k < max_iterations):

        # Definindo o valor e a posição do maior elemento de A
        p, q, mx = find_position(A)

        # Verificando se todos os elementos fora da diagonal são "0"
        if mx < tol:
            print("Total de interações: ", k)
            print("Autovalores Jacobi")
            print(A)
            print("Autovetores Jacobi")
            print(V)
            return A, V

        # Aplicando a rotação de Jacobi no maior elemento
        U = jacobi_rotation(A, p, q)
        
        # Atualizando A (Autovalores) e V (Autovetores)
        A = U.T @ A @ U
        V = V @ U
        k += 1

    print("Número máximo de iterações atingido")

    return A, V


def solve_svd_jacobi(A, tol=1e-10, max_iterations=1000):

    # A = U S VT

    M = A.T @ A

    eigenvalues_matrix, V = solve_jacobi(
        M.copy(),
        tol,
        max_iterations
    )

    eigenvalues = np.diag(eigenvalues_matrix)

    eigenvalues = np.maximum(eigenvalues, 0)

    singular_values = np.sqrt(eigenvalues)

    idx = np.argsort(singular_values)[::-1]

    singular_values = singular_values[idx]
    V = V[:, idx]

    r = np.sum(singular_values > 1e-12)

    singular_values = singular_values[:r]
    V = V[:, :r]

    U = np.zeros((A.shape[0], r))

    for i in range(r):

        U[:, i] = (
            A @ V[:, i]
        ) / singular_values[i]

    VT = V.T

    return U, singular_values, VT