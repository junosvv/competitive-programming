t=int(input())
for _ in range(t):
    n=input()
    if (n.count("0") != 0 and sum(int(i) for i in n)%3==0):
        cnt = 0
        for i in n:
            if int(i)%2==0:
                cnt += 1
        if cnt >= 2:
            print("red")
        else:
            print("cyan")
    else:
        print("cyan")
