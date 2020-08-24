"""n = 12
anoms = 0
for i in range(2**n):
    count = 0
    x=i
    while True:
        count += 1
        if x%2==1:
            x //= 2
        else:
            x //= 2
            x += 2**(n-1)
        if x == i:
            break
    if count != 2*n:
        t = bin(i)[2:]
        print("0"*(n-len(t))+t)
        anoms += 1


if x[0] == '0':
    k = 1
    while k<n and x[k] == '0':
        k += 1
    comp = "".join(str((i//k)%2) for i in range(n))
    if x < comp:
        k += 1
else:
    k = 1
    while k<n and x[k] == '1':
        k += 1
    comp = "".join(str((1+i//k)%2) for i in range(n))
    if x < comp:
        k -= 1"""


MOD = 998244353

n = int(input())
x = input()


def binToInt(x):
    result = 0
    t = 1
    i = 0
    while i < len(x):
        if x[~i] == '1':
            result += t
            result %= MOD
        i += 1
        t *= 2
        t %= MOD
    return result


def getCompStr(pref, copies):
    inv = "".join(str(1-int(c)) for c in pref)
    if copies%2 == 1:
        return (pref+inv)*(copies//2) + pref
    return (pref+inv)*(copies//2)


d = 1
factors = []
while d*d <= n:
    if n%d == 0:
        factors.append(d)
        if (d*d != n):
            factors.append(n//d)
    d += 1
factors.sort()

defects = 0
result = 0
computedDefects = {}
for size in factors:
    numComps = n//size
    if numComps%2==0 or numComps < 3:
        continue
    pref = x[:size]
    curDefects = binToInt(pref)
    for s in computedDefects:
        if size%s == 0 and (size//s)%2 == 1:
            curDefects -= computedDefects[s]
            curDefects %= MOD
    if getCompStr(pref, n//size) <= x:
        curDefects += 1
        curDefects %= MOD
    computedDefects[size] = curDefects
    defects += curDefects
    defects %= MOD
    result += curDefects*2*size
    result %= MOD


result += (binToInt(x)+1-defects)*2*n
result %= MOD
print(result)