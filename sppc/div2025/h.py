rx = ry = by = 0
bx = 1

n = int(input())
s = input()

swaps = 0
for c in s:
    if c == 'B':
        rx, ry, bx, by = bx, by, rx, ry
        swaps ^= 1
    else:
        if rx == bx:
            if ry > by:
                rx, ry = rx+1, ry-1
            else:
                rx, ry = rx-1, ry+1
        else:
            if rx > bx:
                rx, ry = rx-1, ry-1
            else:
                rx, ry = rx+1, ry+1

if swaps:
    print(bx, by)
else:
    print(rx, ry)
