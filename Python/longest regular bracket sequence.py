string = input()

longest = 0
tempLongest = 0

substring = 0

openBracket = 0

for i in range(len(string)):
    if string[i] == '(':
        openBracket += 1
    elif string[i] == ')' and openBracket != 0:
        openBracket -= 1
        tempLongest += 2
    
    if (string[i] == ')' and openBracket == -1) or i == len(string)-1:
        if tempLongest > longest:
            longest = tempLongest
            substring = 1
        elif tempLongest == longest:
            substring += 1
        tempLongest = 0

if longest == 0:
    print(0, 1)
elif longest != 0:
    print(longest, substring)