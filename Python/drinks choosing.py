from math import floor

n, k = input().split()
n = int(n)
k = int(k)

studentsFavourite = [0 for i in range(k+1)]

for i in range(n):
    favourite = int(input())
    studentsFavourite[favourite] += 1

studentsFavouriteRemainder = [i%2 for i in studentsFavourite]

totalRemainder = sum(studentsFavouriteRemainder)

unhappy = floor(totalRemainder / 2)

print(n - unhappy)