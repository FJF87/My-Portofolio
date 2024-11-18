n = int(input())
queenx, queeny = input().split()
kingx, kingy = input().split()
destx, desty = input().split()

queenx = int(queenx)
queeny = int(queeny)

kingx = int(kingx)
kingy = int(kingy)

destx = int(destx)
desty = int(desty)

if desty < queeny < kingy:
    print("NO")
elif desty > queeny > kingy:
    print("NO")
elif destx < queenx < kingx:
    print("NO")
elif destx > queenx > kingx:
    print("NO")
else:
    print("YES")