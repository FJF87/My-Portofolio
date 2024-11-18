n, street = input().split()
n = int(n)
street = int(street)

lanterns = input().split()
lanterns = [int(i) for i in lanterns]
lanterns.sort()

spaces = [(lanterns[i+1] - lanterns[i])/2 for i in range(n-1)]
spaces.append(lanterns[0])
spaces.append(street - lanterns[-1])

print(max(spaces))