cases = int(input())

for i in range(cases):
    numberOfSpot, askedHour = input().split()
    numberOfSpot = int(numberOfSpot)
    askedHour = int(askedHour)

    catA = numberOfSpot
    catB = 1

    for j in range(1, askedHour):
        catA -= 1

        if catA == 0:
            catA = numberOfSpot

        catB += 1

        if catB == numberOfSpot + 1:
            catB = 1
        
        if catB == catA:
            catB += 1
    
    print(catB)