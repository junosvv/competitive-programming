MOD = 1000000007

def xGCD(a, b, x, y):
    if (b == 0):
        x[0] = 1
        y[0] = 0
        return a
    x1 = [0]
    y1 = [0]
    gcd = xGCD(b, a%b, x1, y1)
    x[0] = y1[0]
    y[0] = x1[0] - (a//b)*y1[0]
    return gcd

def modfact(n):
    result = 1
    while (n > 1):
        result = (result*n)%MOD
        n -= 1
    return result

def modmult(a, b):
    return (a*b)%MOD

def inverse(a):
    x = [0]
    y = [0]
    xGCD(a, MOD, x, y)
    return x[0]

def bc(n, k):
    return modmult(modmult(modfact(n), inverse(modfact(k))), inverse(modfact(n - k)))

x, y = map(int, input().split())
if (x+y)%3 != 0:
    print(0)
else:
    row = (x+y)//3
    k = x-row
    if (0 <= k and k <= row):
        print(bc(row, k))
    else:
        print(0)