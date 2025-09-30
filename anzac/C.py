X = int(input())
BIG = pow(10, 6) + 10
is_prime = [True for i in range(BIG)]
is_prime[0] = False
is_prime[1] = False
for i in range(2, BIG):
    if is_prime[i]:
        for j in range(2 * i, BIG, i):
            is_prime[j] = False
        
t = 0
while X > 3:
    for i in range(2, X):
        if is_prime[i] and is_prime[X-i]:
            X = X - i - i
            t += 1
            break
print(t)