from cmath import sqrt

n = 3
A = [[0 for x in range(n)] for y in range(n)]
l = [[0 for x in range(n)] for y in range(n)]

A[0][0] =  4
A[1][0] =  2
A[2][0] =  0

A[0][1] =  2
A[1][1] =  5
A[2][1] =  2

A[0][2] =  0
A[1][2] =  2
A[2][2] =  5


l[0][0] = 1
l[1][1] = 1
l[2][2] = 1

for j in range(0, n):
    for i in range(j + 1, n):
    
        if i < j:
            l[i][j] = 0
        elif i == j:
            sum = 0
            for k in range(0, i):
                sum += l[i][k]**2

            l[i][j] = sqrt(A[i][i] - sum)

        elif i > j:
            sum = 0
            for k in range(0, j):
                sum += l[i][k] * l[j][k]

            l[i][j] = (1 / l[j][j])*(A[i][j] - sum)

        for k in range(j, n):
            A[i][k] = A[i][k] - A[i][j] * A[j][k]



for j in range(0, n):
    for i in range(0, n):
        if i < j:
            continue;

        sum = 0
        for k in range(0,j):
            sum += l[i][k]*l[j][k]
        A[i][j] = sum

for row in A:
    print(row)