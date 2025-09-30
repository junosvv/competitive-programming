n, m = map(int, input().split())
n += 1
stats = [[] for _ in range(n)]
for i in range(m):
    inp = [int(i) for i in input().split()]
    for j in range(1, len(inp)):
        stats[inp[j]].append(i)

G = [[0]*m for _ in range(m)]
for i in range(n):
    for j in stats[i]:
        for k in stats[i]:
            G[j][k] = 1

res = [1000000000000]*n
for i in range(1, n):
    dist = [-1]*m
    for j in stats[i]:
        dist[j] = 0
    q = list(stats[i])
    qi = 0

    while qi < len(q):
        u = q[qi]
        qi += 1

        for v in range(m):
            if G[u][v] and dist[v] == -1:
                dist[v] = 1 + dist[u]
                q.append(v)

    res[i] = max(dist)

res.sort()
mn = min(res)
print(res.count(mn), mn)
