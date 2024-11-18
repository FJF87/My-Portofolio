from math import floor

case = int(input())

for i in range(case):
    string = input()
    x,n,m = string.split()
    x = int(x)
    n = int(n)
    m = int(m)

    while x >= 0 and (n > 0 or m > 0):
        if n > 0 and x > 10:
            x = floor((x/2) + 10)
            n -= 1
        elif m > 0:
            x -= 10
            m -= 1
        else:
            break

    if x <= 0:
        print("YES")
    else:
        print("NO")