cases = int(input())
rectangles = []

for i in range(cases):
    number = input()
    a, b = number.split()
    rectangles.append([int(a), int(b)])

before = max(rectangles[0])

for i in range(cases):
    now = max(rectangles[i])

    if now > before:
        now = min(rectangles[i])

    if now > before:
        print("NO")
        break
    elif i == cases-1:
        print("YES")
    
    before = now