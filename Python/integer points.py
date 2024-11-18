t = int(input())

for i in range(t):
    n = int(input())
    p = input().split()
    p = [int(j) for j in p]

    peven = [j for j in p if j%2==0]
    podd = [j for j in p if j%2==1]

    m = int(input())
    q = input().split()
    q = [int(j) for j in q]

    qeven = [j for j in q if j%2==0]
    qodd = [j for j in q if j%2==1]

    total = len(peven) * len(qeven) + len(podd) * len(qodd)
    print(total)