import math

fromUser = input().split()
N = int(fromUser[0])
M = int(fromUser[1])
A = int(fromUser[2])
needx = math.floor(N/A)
if N % A != 0:
    needx += 1
needy = math.floor(M/A)
if M % A != 0:
    needy += 1
print(needx*needy)