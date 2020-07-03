n=int(input())
arr=list(map(lambda x:int(x)>0,input().split()))

pos = neg = lastpos = lastneg = curpos = curneg = 0
for i in range(n):
    if arr[i]:
        curpos = 1+lastpos
        curneg = lastneg
    else:
        curpos = lastneg
        curneg = 1+lastpos
    pos += curpos
    neg += curneg
    lastpos = curpos
    lastneg = curneg

print(neg,pos)
