n = int(input())
arr = list(sorted(map(int, input().split())))

xx = 0
yy = 0
i = 0
j = n-1
while i < j:
    xx += arr[i]
    yy += arr[j]
    i += 1
    j -= 1

if i == j:
    yy += arr[i]
print(xx*xx+yy*yy)
