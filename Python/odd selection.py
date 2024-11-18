cases = int(input())

for i in range(cases):
    listSize, choose = input().split()
    listSize = int(listSize)
    choose = int(choose)

    numbers = input().split()
    numbers = [int(j)%2 for j in numbers]

    totalOddNumber = sum(numbers)
    totalEvenNumber = len(numbers) - totalOddNumber

    if totalOddNumber == 0:
        print("No")
    else:
        totalOddNumber -= 1
        choose -= 1
        
        while choose > 1 and totalOddNumber > 1:
            choose -= 2
            totalOddNumber -= 2
        
        if choose > 0 and totalEvenNumber >= choose:
            print("Yes")
        elif choose > 0 and totalEvenNumber < choose:
            print("No")
        elif choose == 0:
            print("Yes")