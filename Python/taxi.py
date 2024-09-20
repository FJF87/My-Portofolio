import math

T = input()
children = input().split()
children = [int(x) for x in children]
amountChildren = [
    children.count(1),
    children.count(2),
    children.count(3),
    children.count(4)
]

# result = math.ceil(sum(children) / 4)
# print(result)