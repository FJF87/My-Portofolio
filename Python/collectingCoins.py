T = int(input())
for i in range(T):
    N = input().split()
    A = int(N[0])
    B = int(N[1])
    C = int(N[2])
    P = int(N[3])
    needed1 = 3*max(A,B,C) - (A+B+C)
    if (P-needed1)%3 == 0:
        print("YES")
    else:
        print("NO")