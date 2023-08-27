names = input().split()

swaps = int(input())
for i in range(swaps):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    temp = names[a]
    names[a] = names[b]
    names[b] = temp 

print(" ".join(names))
