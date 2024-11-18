case = int(input())

for i in range(case):
    oldString = input()
    oldStringLen = len(oldString)

    lenNow = 1
    oldLen = 0

    newString = oldString
    while oldLen != lenNow:
        oldLen = len(newString)
        newString = newString.replace("01", "")
        newString = newString.replace("10", "")
        lenNow = len(newString)

    newStringLen = len(newString)
    possibleMove = (oldStringLen - newStringLen) / 2

    if possibleMove % 2 == 0:
        print("NET")
    elif possibleMove % 2 == 1:
        print("DA")