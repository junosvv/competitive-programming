import collections
out = {}
n, m = map(int, input().split())
for i in range(m):
    out[i+1] = list(map(int, input().split()))[1:]
inter = [0]
inter.extend(list(map(int, input().split())))

intervis = [0 for i in range(m+1)]
visited = [-1 for i in range(n+1)]

visited[1] = 0

q = []

q.append(1)

qi = 0

found = False
while qi < len(q):
    i = q[qi]
    qi += 1
    if not intervis[inter[i]]:
        intervis[inter[i]] = 1
        for j in out[inter[i]]:
            if visited[j] == -1:
                visited[j] = 1 + visited[i]
                q.append(j)
                if j == n:
                    found = True
                    break
    if found:
        break
                
print(visited[n])


        
