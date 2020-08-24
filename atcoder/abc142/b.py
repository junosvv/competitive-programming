n,k = map(int,input().split())
result = 0
for i in input().split():
    if int(i) >= k:
        result += 1
print(result)