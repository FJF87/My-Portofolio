cases = int(input())

for i in range(cases):
    listLen, numberQueries = input().split()
    listLen = int(listLen)
    numberQueries = int(numberQueries)

    listNumber = input().split()
    listNumber = [int(j) for j in listNumber]

    for j in range(numberQueries):
        inputNumber = input().split()
        inputNumber = [int(k) for k in inputNumber]
        start, end, newNumber = inputNumber
        copyListNumber = listNumber.copy()

        for k in range(start-1, end):
            copyListNumber[k] = newNumber
        
        if sum(copyListNumber) % 2 == 1:
            print("YES")
        elif sum(copyListNumber) % 2 == 0:
            print("NO")