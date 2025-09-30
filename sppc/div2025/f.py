n = int(input())
pairs = []

for i in range(n):
    x, s = map(int, input().split())
    pairs.append((x-s, x+s, x))

pairs.sort()
L = [0]*n
R = [0]*n
H = [0]*n
for i in range(n):
    L[i] = pairs[i][0]
    R[i] = pairs[i][1]
    H[i] = pairs[i][2]

suff = list(R)
for i in range(n-2, -1, -1):
    suff[i] = min(suff[i], suff[i+1])

res = 0
safe = 0
i = -1
while safe < n:
    res += 1
    x = suff[safe]
    while i+1 < n and H[i+1] <= x:
        i += 1
    while safe < n and L[safe] <= H[i]:
        safe += 1

print(res)
