Q = int(input())

results = []

for _ in range(Q):
    n = int(input())
    zeroes = 0
    ones = 0
    fine = False
    for _ in range(n):
        msg = input()
        zeroes += msg.count("0")
        ones += msg.count("1")
        if len(msg)%2 == 1:
            fine = True
    if not fine and zeroes%2 == 1 and ones%2 == 1:
        results.append(n-1)
    else:
        results.append(n)

for i in results:
    print(i)
