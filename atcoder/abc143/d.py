N = int(input())
arr = list(sorted(map(int, input().split())))

memo = [0]*1001
for x in range(1001):
    for i in arr:
        if i < x:
            memo[x] += 1

result = 0
for a in range(N):
    for b in range(a+1, N):
        aa = arr[a]
        bb = arr[b]
        if aa+bb > 1000:
            result += N-b-1
        else:
            result += memo[aa+bb]-b-1

print(result)