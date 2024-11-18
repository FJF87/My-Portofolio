string = input()

amountOf4 = string.count('4')
amountOf7 = string.count('7')

if amountOf4 == 0 and amountOf7 == 0:
    print("-1")
elif amountOf4 > amountOf7:
    print("4")
elif amountOf7 > amountOf4:
    print("7")
elif amountOf4 == amountOf7:
    index4 = string.find('4')
    index7 = string.find('7')
    if index4 < index7:
        print("4")
    elif index7 < index4:
        print("7")