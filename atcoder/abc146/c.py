a,b,x=map(int,input().split())

best = 0
for d in range(1, 10):
    if int("9"*d)*a+d*b <= x:
        best = "9"*d
    else:
        if int("1"+"0"*(d-1))*a+d*b > x:
            break
        best = (x-b*d)//a
        break
big = int("1"+"0"*9)
if big*a+10*b <= x:
    best = big
print(best)