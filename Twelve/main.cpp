#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;


int startIndex = -1;

bool checkIfRight(tuple<int, int> startPoint, tuple<int, int> selectedPoint, tuple<int, int> checkPoint) {

    tuple<int, int>vectorSelected = make_tuple(get<0>(selectedPoint) - get<0>(startPoint), get<1>(selectedPoint) - get<1>(startPoint));
    tuple<int, int>   vectorCheck = make_tuple(get<0>(checkPoint) - get<0>(startPoint), get<1>(checkPoint) - get<1>(startPoint));

    float det = get<0>(vectorSelected) * get<1>(vectorCheck) - get<1>(vectorSelected) * get<0>(vectorCheck);

    return det < 0;
}

deque < tuple<int, int> > warpList;
tuple<int, int> M[] = {
           make_tuple(2,0),
           make_tuple(4,4),
           make_tuple(0,3),
           make_tuple(2,9),
           make_tuple(6,6),
           make_tuple(5,1),
           make_tuple(8,2),
           make_tuple(9,7),
};

tuple<int, int> getMin() {

    int minX = 999;
    int minY = 999;
    int minIndex = 0;

    for (int i = 0; i < 8; i++)
    {
        if (get<1>(M[i]) < minY) {
            minY = get<1>(M[i]);
            minX = get<0>(M[i]);
            minIndex = i;
        }
        else if (get<1>(M[i]) == minY && get<0>(M[i]) < minX) {
            minY = get<1>(M[i]);
            minX = get<0>(M[i]);
            minIndex = i;
        }
    }
    startIndex = minIndex;
    return M[minIndex];
}




int main() {



    tuple<int, int> startPoint = getMin();
    warpList.push_front(startPoint);


    while (true) {
        int checkIndex = startIndex+1;

        for (int i = 0; i < 8; i++) {
            if (checkIfRight(warpList.front(), M[checkIndex], M[i])) {
                checkIndex = i;
            }

        }

        if (checkIndex == startIndex) {
            break;
        }

        warpList.push_front(M[checkIndex]);
    }




    for (tuple<int, int> item : warpList) {
        cout << get<0>(item) << " : " << get<1>(item) << std::endl;
    }
}

