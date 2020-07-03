answers = []
T = int(input())
for t in range(T):
    oddsA=oddsB=evensA=evensB = 0

    input()
    for ii in input().split():
        i = int(ii)
        if i%2==0:
            evensA += 1
        else:
            oddsA += 1
    input()
    for ii in input().split():
        i = int(ii)
        if i%2==0:
            evensB += 1
        else:
            oddsB += 1

    answers.append(evensA*evensB+oddsA*oddsB)

for i in answers:
    print(i)
