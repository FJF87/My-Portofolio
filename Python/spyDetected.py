T = int(input())
for i in range(T):
    N = int(input())
    numbers = input().split()
    numbers = [int(x) for x in numbers]
    sorted = numbers.copy()
    sorted.sort()
    if sorted[0] != sorted[1]:
        differ = sorted[0]
    else:
        differ = sorted[N-1]
    indexDiffer = numbers.index(differ)
    print(indexDiffer+1)