import collections

line1 = [int(i) for i in input().split()]
rows = []
for i in range(line1[0]):
    rows.append(input())

bitmap = []
for j in range(line1[1]):
    bitmap.append(len(set([rows[i][j] for i in range(line1[0])])) == 1)

a = 0
maxA = 0

for i in range(len(bitmap)):
    if not bitmap[i]:
        maxA = max(a, maxA)
        a = 0
    else:
        a += 1

maxA = max(a, maxA)

print(maxA)



        
