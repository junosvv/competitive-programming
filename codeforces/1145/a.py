N = int(input())
array = [int(i) for i in input().split()]

size = 2
foundany = False
while size <= N:
    for i in range(0, N, size):
        if array[i:i+size] == sorted(array[i:i+size]):
            foundany = True
            break
    if not foundany:
        break
    foundany = False
    size *= 2

print(size//2)
