n, k = map(int, input().split())
a = [int(i) for i in input().split()]

for i in range(n):
    a[i] -= k

a = [0] + a
for i in range(1, n+1):
    a[i] += a[i-1]

suff = list(a)
for i in range(n-1, -1, -1):
    suff[i] = max(suff[i], suff[i+1])

res = 0
for l in range(n):
    b = n
    r = l
    while b >= 1:
        while r+b <= n and suff[r+b] >= a[l]:
            r += b
        b //= 2
    res = max(res, r-l)
print(res)

