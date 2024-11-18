a, b = input().split()

a = int(a)
b = int(b)

if a == 0 and b == 0:
    print("NO")
elif a - b >= -1 and a - b <= 1:
    print("YES")
else:
    print("NO")