

def camino_unico(mapa, m, n, i, j):
    if i < 0 or j < 0 or i >= m or j >= n or mapa[i][j] == 1 or memo[i][j] != -1:
        return 0
    if i == m - 1 and j == n - 1:
        return 1
    if memo[i][j] != -1:
        return memo[i][j]
    memo[i][j] = camino_unico(mapa, m, n, i + 1, j) + camino_unico(mapa, m, n, i, j + 1)
    return memo[i][j]


m = 3
n = 3

memo = [[-1 for _ in range(n)] for _ in range(m)]

mapa = [[0, 0, 0], 
        [0, 0, 0],
        [0, 1, 0]]

camino = camino_unico(mapa, m, n, 0, 0)
print(camino)