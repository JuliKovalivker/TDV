
# variables globales
s_ = []
res = []

def subconjuntos_rec(s, k, s_):
    if k == len(s):
        res.append(s_)
        return
    s_.append(s[k])
    subconjuntos_rec(s, k+1, s_.copy())
    s_.pop()
    subconjuntos_rec(s, k+1, s_.copy())
    return

def subconjuntos(s):
    subconjuntos_rec(s, 0, s_)
    return

s = [1, 2, 3]
subconjuntos(s)
print(res)