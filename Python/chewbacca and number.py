number = input()

number = number.replace('5', '4')
number = number.replace('6', '3')
number = number.replace('7', '2')
number = number.replace('8', '1')
number = number.replace('9', '0')

if number[0] == '0':
    number = number.replace('0', '9', 1)

print(number)