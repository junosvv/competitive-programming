n = int(input())
strs = [input() for _ in range(n)]
mins = []
maxs = []
for i in range(n):
    mn, mx = list(sorted([strs[i], strs[i][::-1]]))
    mins.append(mn)
    maxs.append(mx)

mins.sort()
maxs.sort()

def index(lst, key):
    n = len(lst)
    k = -1
    b = n
    while b >= 1:
        while k+b < n and lst[k+b] < key:
            k += b
        b //= 2
    return k+1

for i in range(n):
    mn, mx = list(sorted([strs[i], strs[i][::-1]]))
    print(index(maxs, mn), index(mins, mx)-(mn!=mx))
