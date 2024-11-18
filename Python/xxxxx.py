cases = int(input())

for i in range(cases):
    listSize, hatedNumber = input().split()
    listSize = int(listSize)
    hatedNumber = int(hatedNumber)

    numbers = input().split()
    numbers = [int(int(j) % hatedNumber) for j in numbers]

    sumNumbers = sum(numbers)

    if sumNumbers % hatedNumber != 0:
        print(len(numbers))
    elif sumNumbers % hatedNumber == 0:
        nonZeroNumbers = [j for j in numbers if j != 0]

        if len(nonZeroNumbers) == 0:
            print(-1)
        elif len(nonZeroNumbers) > 0:
            print(len(numbers) - 1)