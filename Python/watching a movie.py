moments, skip = input().split()
moments = int(moments)
skip = int(skip)

totalMinutes = 0

for i in range(moments):
    newMinutes = input().split()
    newMinutes = [int(j) for j in newMinutes]

    unneededMinutes = newMinutes[0] % skip
    
    if unneededMinutes == 0:
        totalMinutes += (newMinutes[1] - newMinutes[0] + 1)
    elif unneededMinutes != 0:
        totalMinutes += (unneededMinutes + (newMinutes[1] - newMinutes[0]))

print(totalMinutes)