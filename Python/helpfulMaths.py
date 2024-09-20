board = input().split(sep="+")
board.sort()
j=0
for i in board:
    if j != len(board)-1:
        print(i, "+", sep="", end="")
    else:
        print(i)
    j+=1