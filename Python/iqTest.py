T = int(input())
numbers = input().split(sep=" ")
numbers = [int(x) for x in numbers]
differ = [x%2 for x in numbers]
cpy = differ.copy()
cpy.sort()
indToFind = 0
if cpy[0] == cpy[1]:
    indToFind = cpy[T-1]
else:
    indToFind = cpy[0]
indToFind = differ.index(indToFind)
print(indToFind+1)