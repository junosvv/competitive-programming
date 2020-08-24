s = input()
n = len(s)

i = 0
numA = 0
res = 0
while i < n-1:
    if s[i] == 'A':
        numA += 1
    elif s[i] == 'B' and s[i+1] == 'C':
        res += numA
        i += 1
    else:
        numA = 0
    i += 1
print(res)