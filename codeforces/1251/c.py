T = int(input())

results = []

for _ in range(T):
    msg = input()
    odds = []
    evens = []
    for c in msg:
        if int(c)%2 == 0:
            evens.append(c)
        else:
            odds.append(c)
    i=j=0
    out = []
    while i < len(odds) and j < len(evens):
        if int(odds[i]) < int(evens[j]):
            out.append(odds[i])
            i += 1
        else:
            out.append(evens[j])
            j += 1
    while i < len(odds):
        out.append(odds[i])
        i += 1
    while j < len(evens):
        out.append(evens[j])
        j += 1
    results.append("".join(out))

for i in results:
    print(i)
