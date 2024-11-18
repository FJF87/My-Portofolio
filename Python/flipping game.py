cases = int(input())
numbers = input().split()
numbers = [int(i) for i in numbers]

initialAmountOfOne = sum(numbers)
maxNumberOfOne = 0

for i in range(cases):
    for j in range(i, cases):
        amountOfZero = sum([1 for k in range(i, j+1) if numbers[k] == 0])
        amountOfOne = sum([1 for k in range(i, j+1) if numbers[k] == 1])

        tempOne = initialAmountOfOne - amountOfOne + amountOfZero
        maxNumberOfOne = max(maxNumberOfOne, tempOne)

print(maxNumberOfOne)