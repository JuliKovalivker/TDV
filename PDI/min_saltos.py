

def saltos(vec, i):
    if vec[i] + i >= len(vec):
        return 1;
    max = 0;
    for j in range(i + 1, min(len(vec), i + 1 + vec[i])):
        if vec[j] > max:
            max = j;
    return 1 + saltos(vec, max)


arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
print(saltos(arr, 0))