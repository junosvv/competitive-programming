n, x = map(int, input().split())
a = list(map(int, input().split()))

# array size nxn filled with zeroes
minrange = [[0 for j in range(n)] for i in range(n)]
for r in range(n):
    for l in range(r):
        minrange[l][r] = min(minrange[l][r-1], a[r])
    minrange[r][r] = a[r]

res = int(1e18) # 10^18 is basically infinity
for k in range(n):
    cur = k*x
    for i in range(n):
        if i-k >= 0:
            cur += minrange[i-k][i]
        else:
            cur += min(minrange[0][i], minrange[i-k+n][n-1])
    res = min(res, cur)

print(res)