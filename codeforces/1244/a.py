def dd(a,b):
    if a%b == 0:
        return a//b
    return a//b + 1

inps = []
T = int(input())
for _ in range(T):
    a,b,c,d,k = map(int,input().split())
    inps.append((a,b,c,d,k))

for a,b,c,d,k in inps:
    pens = dd(a,c)
    pencils = dd(b,d)
    if pens+pencils <= k:
        print(pens, pencils)
    else:
        print(-1)
