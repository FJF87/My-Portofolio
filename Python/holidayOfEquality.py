N = int(input())
money = input().split(sep=" ")
money = [int(i) for i in money]
max = money[0]
i = 1
while i < len(money):
    if max < money[i]:
        max = money[i]
    i+=1
moneyNeeded = 0
for i in money:
    moneyNeeded += max - i
print(moneyNeeded)