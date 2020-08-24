H, W = map(int, input().split())

# array size HxW filled with zeroes
black = [[0 for c in range(W)] for r in range(H)]
# array size HxW filled with 10^18 (basically infinity)
dp = [[int(1e18) for c in range(W)] for r in range(H)]

for r in range(H):
    line = input()
    for c in range(W):
        black[r][c] = (line[c] == '#')

dp[0][0] = black[0][0] # this case is handled separately

for r in range(H):
    for c in range(W):
        if r >= 1:
            # r-1 can be indexed
            dp[r][c] = min(dp[r][c], dp[r-1][c] + (black[r][c] and not black[r-1][c]))
        if c >= 1:
            # c-1 can be indexed
            dp[r][c] = min(dp[r][c], dp[r][c-1] + (black[r][c] and not black[r][c-1]))

print(dp[H-1][W-1])