
from operator import indexOf

def checkIfRight(startPoint, selectedPoint, checkPoint):

    vectorSelected = (selectedPoint[0] - startPoint[0], selectedPoint[1] - startPoint[1] )
    vectorCheck    = (checkPoint[0]    - startPoint[0],    checkPoint[1] - startPoint[1] )

    det = vectorSelected[0] * vectorCheck[1] - vectorSelected[1] * vectorCheck[0]

    return det < 0

M = [(4, 4), (2, 0), (2, 9), (6, 6), (5, 1), (0, 3), (8, 2), (9, 7)]
warpList = []

startPoint =  min(M, key = lambda t: t[1])

warpList.append(startPoint)

while True:
    checkIndex = indexOf(M,warpList[-1]) - 1

    for i,point in enumerate(M):
        if checkIfRight(warpList[-1], M[checkIndex], point):
            checkIndex = i

    if(warpList.count(M[checkIndex])):
        break

    warpList.append(M[checkIndex])

print(warpList)