n = int(input())
votes = {}
for i in range(n):
    name = input()
    if name not in votes:
        votes[name] = 0
    votes[name] += 1

votes["Philogophers"] = 0

score = sorted(votes.items(), key = lambda x : -x[1])
if (score[0][1] == score[1][1]):
    val = score[0][1]
    names = sorted([name[0] for name in score if name[1] == val])
    output = ", ".join(names) + "."
    print(f"Tie between {output}")
else:
    val = "vote"
    if score[0][1] - score[1][1] != 1:
        val += "s"
    print(f"{score[0][0]} won by {score[0][1] - score[1][1]} {val}.")
