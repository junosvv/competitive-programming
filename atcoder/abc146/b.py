n=int(input())
s=input()

print("".join(chr((ord(i)-ord('A')+n)%26+ord('A')) for i in s))