
# variables globales
s_ = []
res = []

def dados_rec(n, k, s, i, s_):
    if i == n:
        if sum(s_) == s and sorted(s_) not in res:
            res.append(sorted(s_))
    else:
        for j in range(1, max(s, k+1)):
            s2 = s_.copy()
            s2.append(j)
            dados_rec(n, k, s, i+1, s2)

def dados(n, k, s):
    dados_rec(n, k, s, 0, s_)
    return


n = 3
k = 4
s = 6
dados(3, 4, 6)
print(res)