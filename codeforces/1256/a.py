q = int(input())
out = [False]*q

for i in range(q):
    bigs,smalls,n,S = map(int,input().split())
    if smalls < S%n:
        continue
    result = S%n
    smalls -= S%n
    result += n*(smalls//n)
    result += n*bigs
    out[i] = result >= S

for i in out:
    if i:
        print("YES")
    else:
        print("NO")
