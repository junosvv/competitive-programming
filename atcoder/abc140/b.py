n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))

res = 0
prev = -1
for i in range(n):
    res += b[a[i]-1]
    if prev+1 == a[i]:
        res += c[prev-1]
    prev = a[i]

print(res)