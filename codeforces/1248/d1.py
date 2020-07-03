n = int(input())
seq = list(input())

def get_comps(seq):
    depth = 0
    components = 0
    lookingfor = 0
    for i in range(n):
        if seq[i] == "(":
            depth += 1
        else:
            depth -= 1
            if depth < lookingfor:
                lookingfor = depth
                components = 1
            elif depth == lookingfor:
                components += 1

    return components

def other(x):
    if x == "(":
        return ")"
    return "("

if n%2 == 1 or seq.count("(") != seq.count(")"):
    print(0)
    print(1,1)
else:
    best1 = 1
    best2 = 1
    bestVal = get_comps(seq)
    for i in range(n):
        for j in range(i+1,n):
            if seq[i] != seq[j]:
                seq[i] = other(seq[i])
                seq[j] = other(seq[j])
                val = get_comps(seq)
                if val > bestVal:
                    best1 = i
                    best2 = j
                    bestVal = val
                seq[i] = other(seq[i])
                seq[j] = other(seq[j])
    print(bestVal)
    print(best1+1,best2+1)
