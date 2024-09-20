N = int(input())
flowers = input().split(sep=" ")
flowers = [int(x) for x in flowers]
maxNum = max(flowers)
minNum = min(flowers)
dif = maxNum - minNum
if maxNum == minNum:
    print(maxNum-minNum)
    #permutation of N-1
else:
    numMax = flowers.count(maxNum)
    numMin = flowers.count(minNum)
    print(maxNum-minNum, numMax*numMin)