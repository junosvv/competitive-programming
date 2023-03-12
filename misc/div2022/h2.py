hopes = ["hopeless", "losing", "winning"]
line1 = [int(i) for i in input().split()]
cards = [int(i) for i in input().split()]
plays = []
for i in range(line1[1]):
    plays.append([int(i) for i in input().split()])

indexDict = {}
for i in range(len(cards)):
    indexDict[cards[i]] = i

def trueIndex(n):
    if n in indexDict:
        return indexDict[n]
    else:
        return len(cards)

playIndices = []
bestIndices = []

for i in range(len(plays)):
    playIndices = [trueIndex(j) for j in plays[i]]
    bestIndices.append(max(playIndices))


lowestCall = min(bestIndices)
if lowestCall == len(cards):
    lowestCall = -1000

for i in range(len(plays)):
    if bestIndices[i] == lowestCall:
        print(hopes[2])
    elif bestIndices[i] == len(cards):
        print(hopes[0])
    else:
        print(hopes[1])





