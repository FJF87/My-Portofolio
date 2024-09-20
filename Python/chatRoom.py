letters = ["h", "e", "l", "l", "o"]
str = input()
j = 0
for i in range(len(str)):
    if j >= 5:
        break
    elif str[i] == letters[j]:
        j+=1
if j == 5:
    print("YES")
else:
    print("NO")