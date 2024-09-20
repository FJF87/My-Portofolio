i = 0
numberList = []

for i in range(3):
    inputNumber = int(input("Enter a number: "))
    numberList.append(inputNumber)

numberList.sort()

print(numberList)