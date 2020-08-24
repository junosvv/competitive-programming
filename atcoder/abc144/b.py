n=int(input())
s=0
for i in range(1,10):
    for j in range(1,10):
        if i*j==n:
            print("Yes")
            s=1
            break
    if s == 1:
        break

if s==0:
    print("No")