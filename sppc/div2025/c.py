n = int(input())
par = [-1]*n
a = [0]*n
children = [[] for _ in range(n)]
for i in range(n):
    par[i], a[i] = map(int, input().split())
    if par[i] != -1:
        par[i] -= 1
        children[par[i]].append(i)

freq = [{} for _ in range(n)]
res = 0
for i in range(n):
    for j in children[i]:
        if a[j] not in freq[i]:
            freq[i][a[j]] = 0
        freq[i][a[j]] += 1

    for j in children[i]:
        res += freq[i].get(a[i]-a[j], 0) - (a[i]-a[j] == a[j])


q = int(input())
for qi in range(q):
    u, x = map(int, input().split())
    u -= 1

    if par[u] != -1:
        res -= 2*(freq[par[u]].get(a[par[u]]-a[u], 0) - (a[par[u]]-a[u] == a[u]))
    for v in children[u]:
        res -= freq[u].get(a[u]-a[v], 0) - (a[u]-a[v] == a[v])

    if par[u] != -1:
        freq[par[u]][a[u]] -= 1
    a[u] += x
    if par[u] != -1:
        if a[u] not in freq[par[u]]:
            freq[par[u]][a[u]] = 0
        freq[par[u]][a[u]] += 1

    if par[u] != -1:
        res += 2*(freq[par[u]].get(a[par[u]]-a[u], 0) - (a[par[u]]-a[u] == a[u]))
    for v in children[u]:
        res += freq[u].get(a[u]-a[v], 0) - (a[u]-a[v] == a[v])
                  
    assert not (res&1)
    print(res // 2)
