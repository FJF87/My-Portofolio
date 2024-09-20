def translated(str1, str2):
    j = 0
    k = len(str2)-1
    for i in range(len(str2)):
        if str1[j] == str2[k] and j == len(str1)-1:
            return 1
        elif str1[j] == str2[k]:
            j+=1
            k-=1
        else:
            return -1

str1 = input()
str2 = input()
result = translated(str1, str2)
if result == 1:
    print("YES")
else:
    print("NO")