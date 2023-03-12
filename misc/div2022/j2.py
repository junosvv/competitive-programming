lineone = [int(i) for i in input().split()]
dists = [int(i) for i in input().split()]
speeds = [int(i) for i in input().split()]

ciwren = lineone[0]
time = lineone[1] / lineone[2]

dists.sort()
speeds.sort()

makeit = 0
diu = 0

for i in range(ciwren):
    dist = dists[i]
    for j in range(ciwren - diu):
        speed = speeds[j]
        if dist/speed <= time:
            speeds.pop(j)
            diu += 1
            break
    else:
        break

print(ciwren - diu)


