cases, totalIceCream = input().split()
cases = int(cases)
totalIceCream = int(totalIceCream)
sadBoy = 0

for i in range(cases):
    operation, amount = input().split()
    amount = int(amount)
    
    if operation == '+':
        totalIceCream += amount
    elif operation == '-':
        if totalIceCream < amount:
            sadBoy+=1
        elif totalIceCream >= amount:
            totalIceCream -= amount

print(totalIceCream, sadBoy)