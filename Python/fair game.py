cardsAmount = int(input())
cards = []
distictCard = []

for i in range(cardsAmount):
    newNumber = int(input())

    cards.append(newNumber)

    if newNumber not in distictCard:
        distictCard.append(newNumber)

if len(distictCard) != 2:
    print("NO")
else:
    x = cards.count(distictCard[0])
    y = cards.count(distictCard[1])
    if x == y and distictCard[0] != distictCard[1]:
        print("YES")
        print(distictCard[0], distictCard[1])
    elif x != y:
        print("NO")