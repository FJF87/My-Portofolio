N = int(input())
vol = input().split(sep=" ")
volumeDrink = 0
for i in vol:
    volumeDrink += int(i)
print(volumeDrink/N)