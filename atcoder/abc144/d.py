import math

a,b,x = map(int,input().split())

z = 2*b-2*x/(a*a)
if z > b:
    print(math.degrees(math.atan(a*b*b/(2*x))))
else:
    print(math.degrees(math.atan((2*b-2*x/(a*a))/a)))