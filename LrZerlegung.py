n = 4

A =  [ [0]*n] * n


A[1][2] = 2

for x in range(0, n):
    for y in range(0, n):
        A[x][y] = { x, y}
   

for x in range(0, n):
    for y in range(0, n):
        print (A[x][y])