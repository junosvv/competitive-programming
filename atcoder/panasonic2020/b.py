r,c = map(int,input().split())

if r==1 or c == 1:
    print(1)
elif (r%2==1 and c%2==1):
    print(r*c//2+1)
else:
    print(r*c//2)