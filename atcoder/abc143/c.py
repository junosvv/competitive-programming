N = int(input())
arr = input()

result = 1
for i in range(1, N):
    if arr[i] != arr[i-1]:
        result += 1

print(result)