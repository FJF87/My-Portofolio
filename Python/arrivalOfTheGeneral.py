N = int(input())
height = input().split(sep=" ")
height = [int(x) for x in height]
minimum = height[0]
maximum = height[0]
indMin = 0
indMax = 0
for i in range(N):
    if minimum >= height[i]:
        minimum = height[i]
        indMin = i
    if maximum < height[i]:
        maximum = height[i]
        indMax = i
if indMax < indMin:
    print(indMax + (N - indMin) - 1)
elif indMax > indMin:
    print(indMax + (N - indMin) - 2)