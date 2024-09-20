def chekStr(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()
    for i in range(len(str1)):
        if str1[i] < str2[i]:
            return -1
        elif str1[i] > str2[i]:
            return 1
        elif i==len(str1)-1 and str1[i] == str2[i]:
            return 0

str1 = input()
str2 = input()
print(chekStr(str1, str2))