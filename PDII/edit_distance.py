

def edit_distance(s,t,i,j):
    if i == 0 or j == 0:
        return max(i, j)
    else:
        if s[i-1] == t[j-1]: return 0 + edit_distance(s, t, i-1, j-1)
        sust = 1 + edit_distance(s, t, i-1, j-1) 
        elim = 1 + edit_distance(s, t, i-1, j)
        agre = 1 + edit_distance(s, t, i, j-1)
        return min(sust, elim, agre)
    
print(edit_distance("messi", "pepsi", 5, 5))