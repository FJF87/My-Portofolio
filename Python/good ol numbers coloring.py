from math import gcd

t = int(input())

for i in range(t):
    a, b = input().split()
    a = int(a)
    b = int(b)

    if gcd(a, b) == 1:
        print("Finite")
    elif gcd(a, b) != 1:
        print("Infinite")
        