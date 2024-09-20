def isPrime(number):
	i = 2
	if number > 1:
		if number==2:
			conclusion = "prime number"
		else:
			while i < number:
				result = number % i
				if result==0:
					conclusion = "composite number"
					break
				else:
					check = number - 1
					if i==check:
						conclusion = "prime number"
						break
				i+=1
	elif number < 0 :
		conclusion = "negative number"
	else:
		conclusion = "neither prime nor composite"
	return conclusion

inputNumber = int(input("Enter a number: "))
print(isPrime(inputNumber))