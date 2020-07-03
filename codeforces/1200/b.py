T = int(input())
result = ""
for _ in range(T):
    n,m,k = map(int, input().split())
    heights = [int(i) for i in input().split()]

    if n == 1:
        result += "YES\n"
    else:
        cur = m
        i = 0
        while i < n-1:
            next_height = max(0,heights[i+1]-k)
            if next_height <= heights[i]:
                cur += heights[i]-next_height
                i += 1
            elif next_height-heights[i] <= cur:
                cur -= (next_height-heights[i])
                i += 1
            else:
                break
        if i == n-1:
            result += "YES\n"
        else:
            result += "NO\n"

print(result,end="")
