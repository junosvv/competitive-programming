n = int(input())
arr = [int(i) for i in input().split()]
result = [0]*n

for i in range(n):
    result[arr[i]-1] = i+1

print(" ".join(str(i) for i in result))