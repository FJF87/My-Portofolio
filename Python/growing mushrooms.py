getInput = input().split()
getInput = [int(i) for i in getInput]
participants, firstRound, secondRound, percentDown = getInput

# minRound = min(firstRound, secondRound)
# maxRound = max(firstRound, secondRound)

resultTable = {}

for i in range(1, participants+1):
    speed = input().split()
    speed = [int(j) for j in speed]
    result1 = round((speed[0] * firstRound) * ((100-percentDown)*0.01) + speed[1] * secondRound, 2)
    result2 = round((speed[1] * firstRound) * ((100-percentDown)*0.01) + speed[0] * secondRound, 2)
    resultTable[i] = max(result1, result2)

resultList = list(resultTable.values())
resultList.sort()
resultList.reverse()

for i in range(participants):
    for j in resultTable:
        if resultList[i] == resultTable[j]:
            print(j, f"{resultTable[j]:.2f}")
            resultTable.pop(j)
            break