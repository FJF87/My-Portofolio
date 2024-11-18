from decimal import Decimal, getcontext

getcontext().prec = 20

n = input()

ndec = Decimal(n)
addition = Decimal('1')
divisor = Decimal('2')

ndec += addition

if ndec == 1:
    print(0)
elif ndec % divisor == 0:
    result = ndec / divisor
    print(result)
elif ndec % divisor == 1:
    print(ndec)