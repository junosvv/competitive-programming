a1f=int(input())
a2f=int(input())
c=int(input())
d=int(input())
if c <= d:
    k1=c
    k2=d
    a1=a1f
    a2=a2f
else:
    k1=d
    k2=c
    a1=a2f
    a2=a1f
n=int(input())

if n <= a1*k1:
    M=n//k1
else:
    M=a1+min((n-a1*k1)//k2,a2)

t = a1*(k1-1)+a2*(k2-1)
if n <= t:
    m=0
else:
    m=n-t

print(m,M)
