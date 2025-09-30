n = int(input())

def divisors(n):
    return [i for i in range(1, n+1) if n%i == 0]

print(sum(n//i - 1 for i in divisors(n)))