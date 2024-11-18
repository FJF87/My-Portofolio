n, x, y = input().split()

n = int(n)
x = int(x)
y = int(y)

days = input().split()
days = [int(i) for i in days]

for i in range(n):
    okay = 1
    for j in range(x):
        j += 1
        if i - j >= 0:
            if days[i-j] < days[i]:
                okay = 0
                break
    
    for k in range(y):
        k += 1
        if i + k < n:
            if days[i+k] < days[i]:
                okay = 0
                break

    if okay == 1:
        print(i+1)
        break