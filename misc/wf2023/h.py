n = int(input())
ps = []
for _ in range(n):
    a,b = map(int, input().split())
    ps.append((a,b))

if ps[0][0] == 0:
    print("impossible")
    exit(0)

inf = 20000000000
aug = [(0,ps[0][0])] + [(ps[i][1],ps[i][0]) for i in range(n-1)] + [(ps[-1][1],inf)]
aug = [(a,b) for (a,b) in aug if a!=b]
n = len(aug)-1
back_ptr = []

lead = 0
lead_i = -1

for i in range(n):
    a,b = aug[i]
    if lead < a:
        print("impossible")
        exit(0)
    back_ptr.append(lead_i)
    if i == n:
        break
    far = a + 3*(b-a)
    if far > lead:
        lead = far
        lead_i = i
    

pos = n
ans = []
while pos != -1:

