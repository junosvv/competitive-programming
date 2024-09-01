a,b = map(int, input().split())
ans = 0
for i in range(a):
    ans += sum(map(int, input().split()))

print(ans/(a*b))