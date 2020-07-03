Q = int(input())
 
result = []
 
for q in range(Q):
    n,k = map(int,input().split())
    arr = list(input())
    numOnes = 0
    succs = 0
    broke = False
    for i in range(n):
        if arr[i] == "0":
            if k >= numOnes:
                k -= numOnes
                succs += 1
            else:
                broke = True
                break
        else:
            numOnes += 1
    if not broke:
        result.append("0"*(n-numOnes)+"1"*numOnes)
    else:
        skipZeroes = succs+1
        skipOnes = numOnes-k
 
        out = ["0"]*succs + ["1"]*skipOnes + ["0"]
 
        for i in range(n):
            if arr[i] == "0":
                if skipZeroes > 0:
                    skipZeroes -= 1
                else:
                    out.append("0")
            else:
                if skipOnes > 0:
                    skipOnes -= 1
                else:
                    out.append("1")
        result.append("".join(out))
 
for i in result:
    print(i)
