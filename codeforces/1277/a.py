t=int(input())

def f(n):
    res = 0
    for d in range(1, 11):
        for r in range(1, 10):
            x = int(str(r)*d)
            if x > n:
                print(res)
                return
            res += 1

for _ in range(t):
    n = int(input())
    f(n)
