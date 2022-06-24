#include <iostream>

int M[][2] = { {2, 0}, {4, 4}, {0, 3}, {2, 9}, {6, 6}, {5, 1}, {8, 2}, {9, 7} };
int size = 8;


int getLowestPoint() {
	int minIndex = -1;
	int minLeft = 999;
	int minHeight = 999;

	for (int i = 0; i < size; i++)
	{
		if (M[i][1] < minHeight) {
			minHeight = M[i][1];
			minLeft = M[i][0];
			minIndex = i;
		}
		else if (M[i][1] == minHeight && M[i][0] < minLeft) {
			minHeight = M[i][1];
			minLeft = M[i][0];
			minIndex = i;
		}
	}
	return minIndex;
}


void swapLowestToFront(int index) {
	int copyX = M[0][0];
	int copyY = M[0][1];

	M[0][0] = M[index][0];
	M[0][1] = M[index][1];

	M[index][0] = copyX;
	M[index][1] = copyY;
}


bool isMoreRight(int startPointX, int startPointY, int currentPointX, int currentPointY, int newPointX, int newPointY) {


	float det = (currentPointX - startPointX) * (newPointY - startPointY) - (newPointX - startPointX) * (currentPointY - startPointY);

	return det > 0;

}

//Correct Index from Overflowing
int cI(int badIndex) {
	return badIndex % size;
}

int main() {


	swapLowestToFront(getLowestPoint());

	int startIndex = 0;

	while (true) {

		int currentIndex = cI(startIndex + 1);
		int newIndex	 = cI(currentIndex + 1);

		int count = 0;

		while (true) {

			bool res = isMoreRight(
				M[startIndex][0], M[startIndex][1],
				M[currentIndex][0], M[currentIndex][1],
				M[newIndex][0], M[newIndex][1]
			);

			if (res) {
				currentIndex = newIndex;
				count = 0;
			}
			else {
				newIndex++;
				count++;
			}


			if (count == size) {
				break;
			}
		}


		if (startIndex == 0) {
			break;
		}
	}
}
