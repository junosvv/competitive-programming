n=int(input())
res=int((n%100)/5)
n -= 105*res
if n == 0 or n >= 100:
    print(1)
else:
    print(0)