str = input()
if len(str) == 1:
    str = str.swapcase()
elif str.isupper():
    str = str.lower()
elif str[1:len(str)].isupper():
    str = str.capitalize()
print(str)