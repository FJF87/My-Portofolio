from math import gcd
from functools import reduce

n = int(input())
nums = input().split()
nums = [int(i) for i in nums]

numsGCD = reduce(gcd, nums)

print(numsGCD * n)