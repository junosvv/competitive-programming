n=int(input())

i=1
best = -1
while i*i <= n:
    if n%i == 0:
        val = i+(n//i)
        if best == -1 or val < best:
            best = val
    i += 1

print(best-2)