cases = int(input())

for i in range(cases):
    goal = int(input())

    if goal == 2:
        print(1)
    elif goal == 4:
        print(2)
    else:
        moves = int(goal / 3)
        if goal % 3 == 1:
            moves += 2
        elif goal % 3 == 2:
            moves += 1

        print(moves)