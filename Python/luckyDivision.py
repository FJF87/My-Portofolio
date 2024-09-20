number = input()
isLuckyNumber = 1
for i in number:
    if i != "4" and i != "7":
        isLuckyNumber = 0
        break

if isLuckyNumber == 0:
    number = int(number)
    if number % 4 == 0 or number % 7 == 0 or number % 47 == 0 or number % 447 == 0 or number % 477 == 0 or number % 474 == 0 or number % 744 == 0 or number % 747 == 0 or number % 774 == 0:
        isLuckyNumber = 1

if isLuckyNumber == 0:
    print("NO")
elif isLuckyNumber == 1:
    print("YES")