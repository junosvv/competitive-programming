N = int(input())
arr = list(map(int,input().split()))

result = 0
for a in range(N):
    for b in range(a+1, N):
        result += arr[a]*arr[b]

print(result)