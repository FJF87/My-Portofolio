N = int(input())
for i in range(N):
    fromUser = input().split(sep=" ")
    number = int(fromUser[0])
    divisor = int(fromUser[1])
    modResult = number%divisor
    if modResult == 0:
        print("0")
    else:
        print(divisor - modResult)