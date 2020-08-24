n=int(input())
a=int(n/1.08)
if int(a*1.08)==n:
    print(a)
elif int((a+1)*1.08) == n:
    print(a+1)
else:
    print(":(")