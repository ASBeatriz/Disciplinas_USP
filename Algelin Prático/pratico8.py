import numpy as np
from numpy.linalg import svd
import math

# Matriz de avaliações
R = np.array([
    [5, 3, 0, 1, 0, 0, 0, 2],
    [4, 0, 0, 1, 2, 0, 0, 0],
    [1, 1, 0, 5, 0, 0, 0, 0],
    [0, 0, 5, 4, 0, 0, 0, 0],
    [3, 0, 0, 0, 4, 0, 0, 5],
    [0, 2, 4, 0, 0, 0, 1, 0],
    [0, 0, 0, 0, 0, 3, 5, 2],
    [2, 0, 3, 0, 0, 0, 0, 4],
    [0, 0, 0, 0, 0, 5, 4, 0],
    [1, 2, 0, 0, 0, 0, 3, 0]
], dtype=float)
print('Matriz de ratings R:')
print(R)

# 1 - Pré-processamento: substituir notas ausentes pela média do usuário
user_means = np.array([np.mean(row[row>0]) if np.any(row>0) else 0 for row in R])
R_filled = R.copy()
for i in range(R.shape[0]):
    R_filled[i, R_filled[i]==0] = user_means[i]

print('\nMatriz preenchida com médias por usuário:')
print(np.round(R_filled, 2))

# 2 - Aplicar SVD
U, S, VT = svd(R_filled, full_matrices=False)

# Redução de dimensionalidade (k=3)
k = 3
S_k = np.diag(S[:k])
U_k = U[:, :k]
VT_k = VT[:k, :]

# 3 - Reconstruir a matriz
R_r = U_k @ S_k @ VT_k

# Arredondar os valores entre 1 e 5
R_r = np.clip(R_r, 1, 5)

print("\nMatriz com as previsões:")
print(np.round(R_r, 2),"\n")

# 4 - Gerar Recomendações

def get_recommendations(R, R_filled, row, n):
    # Seleciona a linha do usuário
    R_row = R[row]
    filled_row = R_filled[row]

    # colunas que tem o valor 0 na matriz original
    cols = np.where(R_row == 0)[0]  

    # valores preenchidos nas colunas correspondentes da matriz preenchida
    values = filled_row[cols]          

    # Ordena e pega os n maiores valores
    order = np.argsort(values)         # ordena de menor pra maior
    top_idx = order[-n:][::-1]         # pega os n maiores e inverte pra decrescente

    # Retorna uma lista com os valores e seus índices (id do filme)
    result = [(float(values[i]), int(cols[i])) for i in top_idx]

    return result


# Imprime as recomendações de cada usuário
for i in range (10):
    rec = get_recommendations(R, R_r, i, 2)
    print(f"Usuário {i+1}: Recomendamos os filmes F{rec[0][1]+1} ({round(rec[0][0], 2)}) e F{rec[1][1]+1} ({round(rec[1][0], 2)})")