case = int(input())

for i in range(case):
    n, sum = input().split()
    n = int(n)
    sum = int(sum)

    result = int(sum / n)
    addition = sum % n

    resultAndAddition = [result for j in range(n)]
    index = 0

    for i in range(addition):
        if index >= n:
            index = 0

        resultAndAddition[index] += 1
        addition-=1

        index+=1
    
    resultAndAddition = [pow(j, 2) for j in resultAndAddition]

    total = 0
    for j in resultAndAddition:
        total += j

    print(total)