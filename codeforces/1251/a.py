t = int(input())
results = []

for _ in range(t):
    msg = input()
    out = [0]*26
    count = 0
    for i in range(len(msg)):
        count += 1
        if i == len(msg)-1 or msg[i] != msg[i+1]:
            if count%2 == 1:
                out[ord(msg[i])-ord('a')] = 1
            count = 0
    results.append("")
    for i in range(26):
        if out[i]:
            results[-1] += chr(i+ord('a'))

for i in results:
    print(i)
