n=int(input())
h=[int(i) for i in input().split()]
res = 0
cur = 0
prev = 0
for i in h:
    if i > prev:
        res = max(res, cur)
        cur = 0
    else:
        cur += 1
    prev = i
res = max(res, cur)
print(res)