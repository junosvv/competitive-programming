n,p,w,d = map(int,input().split())

def gcd(a,b):
    if a == 0:
        return b
    if b == 0:
        return a
    if a < b:
        return gcd(a, b%a)
    return gcd(a%b, b)

g = gcd(w,d)
if p%g != 0:
    print(-1)
else:
    p //= g
    w //= g
    d //= g
    draws = 0
    while p > 0 and p%w != 0:
        p -= d
        draws += 1
    if p < 0:
        print(-1)
    else:
        wins = p//w
        if wins+draws > n:
            print(-1)
        else:
            print(wins, draws, n-wins-draws)
