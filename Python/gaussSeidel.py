def gaussSeidel():
    array = []
    i = 0
    for i in range(3):
        print(f"The {i+1}-th row: ")
        x = float(input("input x: "))
        y = float(input("input y: "))
        z = float(input("input z: "))
        c = float(input("input c: "))
        newRow = [x,y,z,c]
        array.append(newRow)
    
    print(array)
    
    n = int(input("for how many iteration: "))
    x = float(input("starting value of x: "))
    y = float(input("starting value of y: "))
    z = float(input("starting value of z: "))

    # assume that it always converge

    i = 0
    for i in range(n):
        print("iteration ", i)
        print("before count: ")
        print("x is ", x)
        print("y is ", y)
        print("z is ", z)
        print("after count: ")
        x = float((array[0][3] - array[0][1] * y - array[0][2] * z) / array[0][0])
        x = round(x, 2)
        print("x is ", x)
        y = float((array[1][3] - array[1][0] * x - array[1][2] * z) / array[1][1])
        y = round(y, 2)
        print("y is ", y)
        z = float((array[2][3] - array[2][0] * x - array[2][1] * y) / array[2][2])
        z = round(z, 2)
        print("z is ", z)

    print("x is ", x)
    print("y is ", y)
    print("z is ", z)

gaussSeidel()