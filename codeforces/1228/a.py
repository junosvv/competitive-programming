l,r = map(int,input().split())
for i in range(l,r+1):
    s = str(i)
    for c in s:
        if s.count(c) > 1:
            break
    else:
        print(i)
        break
else:
    print(-1)
