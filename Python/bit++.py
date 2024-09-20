N = int(input())
total = 0
for i in range(N):
    op = input()
    if op.find("+") >= 0:
        total = total + 1
    elif op.find("-") >= 0:
        total = total - 1

print(total)