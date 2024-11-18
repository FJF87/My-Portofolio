cases = int(input())

for i in range(cases):
    a, b, c, n = map(int, input().split())
    n -= (3 * max(a, b, c) - (a + b + c))

    if n < 0:
        print("NO")
    elif n % 3 == 0:
        print("YES")
    elif n % 3 != 0:
        print("NO")