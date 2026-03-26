def grafo_completo(n: int) -> list[list[int]]:
    """Dado un número natural n devolver la matriz de adyacencia de un grafo completo con n vértices.
    Ayuda: Asumir que los nodos son {0,1,..,n-1}.
    Args:
        n (int): Cantidad de vértices del grafo.

    Returns:
        List[List[int]]: La matriz de adyacencia de un grafo completo.
    """
    grafo = []
    sub_lista = []
    for i in range(n):
        for j in range(n):
            sub_lista.append(1)
        sub_lista[i] = 0
        grafo.append(sub_lista)
        sub_lista = []
    # pass
    return grafo


def grafo_bipartito_completo(n: int, m: int) -> list[list[int]]:
    """Dado dos números naturales n y m devolver la matriz de adyacencia de un grafo bipartito completo que tiene n vértices en una de
    sus particiones y m vértices en la otra.
    Asumir que los nodos de la primera particion son {0,1,..,n-1} y los de la segunda son {n,n+1,..,n+m-1}
    Args:
        n (int): Cantidad de vértices de la partición izquierda.
        m (int): Cantidad de vértices de la partición derecha.

    Returns:
        List[List[int]]: La matriz de adyacencia de un grafo bipartito completo
    """
    grafo = []
    sub_lista = []
    for i in range(n+m):
        for j in range(n+m):
            if (j<n and i<n) or (j>=n and i>=n):
               sub_lista.append(0)
            elif (j>=n and i<n) or (j<n and i>=n):
                sub_lista.append(1) 
        grafo.append(sub_lista)
        sub_lista = []
    # pass
    return grafo

import math

def grafo_rueda(n: int) -> list[list[int]]:
    """Dado un natural n >= 4 devolver la matriz de adyacencia de un grado rueda de n vértices.
    Asumir que el nodo del centro es n-1 y los nodos del 0 hasta el n-2 forman en círculo en el orden 0-1-..-(n-2).
    Ayuda: https://es.wikipedia.org/wiki/Grafo_rueda
    Args:
        n (int): Cantidad de vértices del grafo.

    Returns:
        List[List[int]]: La matriz de adyacencia de un grafo rueda.
    """
    grafo = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n-1):
        grafo[n-1][i] = 1
        grafo[i][n-1] = 1
        if i == 0:
            grafo[i][n-2] = 1
            grafo[i][1] = 1
        elif i == n-2:
            grafo[i][0] = 1
            grafo[i][n-3] = 1
        else:
            grafo[i][i-1] = 1
            grafo[i][i+1] = 1

    # grafo = []
    # sub_lista = []
    # for i in range(n-1):
    #     if i == 0:
    #         sub_lista.append(0)
    #         sub_lista.append(1)
    #         for j in range(2, n-2):
    #             sub_lista.append(0)
    #         sub_lista.append(1)
    #     elif i == n -2:
    #         sub_lista.append(1)
    #         for j in range(1, n-3):
    #             sub_lista.append(0)
    #         sub_lista.append(1)
    #         sub_lista.append(0)
    #     else:
    #         for j in range(n-1):
    #             if (j == i -1) or (j == i+ 1):
    #                 sub_lista.append(1)
    #             else:
    #                 sub_lista.append(0)
    #     sub_lista.append(1)
    #     grafo.append(sub_lista)
    #     sub_lista = []
    # for i in range(n-1):
    #     sub_lista.append(1)
    # sub_lista.append(0)
    # grafo.append(sub_lista)
    # pass
    return grafo
