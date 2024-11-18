from math import gcd, floor

numbers = input().split()
numbers = [int(i) for i in numbers]
a, b, x, y = numbers

xygcd = gcd(x, y)

xBase = x / xygcd
yBase = y / xygcd

xAmt = floor(a / xBase)
yAmt = floor(b / yBase)

print(min(xAmt, yAmt))