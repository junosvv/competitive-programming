x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())

points = []
cx = x0
cy = y0
while True:
    points.append((cx, cy))
    cx = ax*cx+bx
    cy = ay*cy+by
    if cx > xs and cy > ys and abs(cx-xs)+abs(cy-ys) > t:
        break

n = len(points)

res = 0
for i in range(n):
    for j in range(i, n):
        start = min(abs(xs-points[i][0])+abs(ys-points[i][1]), abs(xs-points[j][0])+abs(ys-points[j][1]))
        final = start + abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1])
        if final <= t:
            res = max(res, j-i+1)

print(res)
