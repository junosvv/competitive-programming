n=int(input())

for i in range(n, n+100):
    if sum(int(j) for j in str(i))%4 == 0:
        print(i)
        break
