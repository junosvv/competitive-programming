width, n, d = map(int,input().split())
lengths = map(int,input().split())

#dist = (n+1)*d + sum(map(int,input().split())) - n

out = [[0,1]]

i = 1
platform = 1
for length in lengths:
    out.append([i,length])
    i += length

success = 0
i = n
x = width+1
while i >= 0:
    x -= d+out[i][1]-1
    if x <= out[i][0]:
        success = 1
        break
    out[i][0] = x
    i -= 1

if success:
    result = [0]*width
    platform = 1
    for start,length in out[1:]:
        for i in range(start-1, start-1+length):
            result[i] = platform
        platform += 1

    print("YES")
    print(" ".join(map(str,result)))
else:
    print("NO")
