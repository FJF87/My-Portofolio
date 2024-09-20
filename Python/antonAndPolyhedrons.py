N = int(input())
total = 0
for i in range(N):
    figure = input()
    if figure == "Tetrahedron":
        total += 4
    elif figure == "Cube":
        total += 6
    elif figure == "Octahedron":
        total += 8
    elif figure == "Dodecahedron":
        total += 12
    elif figure == "Icosahedron":
        total += 20

print(total)