q = int(input())

result = []

for i in range(q):
    n = int(input())
    arr = list(map(int,input().split()))
    out = []

    x = 0
    while x < n-1:
        magic = min(arr[x:])
        if arr[x] == magic:
            out.append(magic)
            x += 1
            continue
        magicIndex = arr.index(magic)
        out.append(magic)
        out += arr[x:magicIndex-1]
        arr[magicIndex],arr[magicIndex-1]=arr[magicIndex-1],arr[magicIndex]
        #print("x", x, "magic", magic, "arr", arr, "out", out)
        x = magicIndex
    out.append(arr[-1])
    result.append(out)

for i in result:
    print(" ".join(map(str,i)))
