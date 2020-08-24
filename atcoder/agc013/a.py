n = int(input())
a = list(map(int, input().split()))

state = -1
res = 1
for i in range(1, n):
    if state == -1:
        if a[i] < a[i-1]:
            state = 0
        elif a[i] > a[i-1]:
            state = 1
    elif (state == 0 and a[i] > a[i-1]) or (state == 1 and a[i] < a[i-1]):
        res += 1
        state = -1

print(res)