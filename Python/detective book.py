n = int(input())
page = input().split()
page = [int(i) for i in page]
page.insert(0, 0)

counter = 0
lastPageRead = 0

while lastPageRead != n:
    counter += 1
    i = lastPageRead + 1
    todayRead = page[i]

    while i <= todayRead:
        if page[i] > todayRead:
            todayRead = page[i]
        i += 1

    lastPageRead = i-1

print(counter)