n = int(input())
d = list(map(int, input().split(" ")))
d.sort()
if n == 2:
    a = d[0]
    b = d[1]
elif n == 3:
    if d[1] - d[2] > d[0] - d[1]:
        a = d[1]
        b = d[2]
    else:
        a = d[0]
        b = d[1]
else:
    a = d[n-2]
    b = d[1]

print(a-b)