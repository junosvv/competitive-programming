t1, t2 = map(int,input().split())
a1, a2 = map(int,input().split())
b1, b2 = map(int,input().split())
 
def ispos(x):
    return x==abs(x)

first = (a1-b1)*t1
second = (a2-b2)*t2
net = first+second
if net == 0:
    print("infinity")
elif ispos(first) == ispos(net):
    print(0)
else:
    res = 1
    first = -abs(first)
    second = abs(second)
    net = first+second
    res += 2*int(abs(first)/net)
    if first%net == 0:
        res -= 1
    print(res)