badBoard = []
for i in range(10):
    inp = [int(i) for i in input().split()]
    if i%2 == 0:
        inp.reverse()
    badBoard.append(inp)
badBoard.reverse()
board = [badBoard[i//10][i%10] for i in range(100)]

cardCount = int(input())

cards = [int(i) for i in input().split()]

p = [0,0,0,0]
pStatus = [0,0,0,0] # -1 means finished, 1 means kiwied
tp = 0

def getNewPlayer(tp):
    tp = (tp + 1) % 4
    if pStatus[tp] > 0:
        pStatus[tp] -= 1
        return getNewPlayer(tp)
    
    elif pStatus[tp] < 0:
        return getNewPlayer(tp)

    return tp

for i in range(len(cards)):
    
    p[tp] += cards[i]

    if p[tp] >= 100:
        p[tp] = 100
        pStatus[tp] = -1
    
    elif board[p[tp]] == -1:
        pStatus[tp] = 1
    
    elif board[p[tp]] != 0:
        p[tp] = board[p[tp]] - 1
    
    if pStatus == [-1,-1,-1,-1]:
        break
    tp = getNewPlayer(tp)

print(" ".join(str(i+1) for i in p))




