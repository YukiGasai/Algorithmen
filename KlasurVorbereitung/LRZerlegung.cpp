#include <iostream>

float A[4][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
};

float L[4][4] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
};

float R[4][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
};


void fillWithInput() {
	A[0][0] = -1;
	A[1][0] =  1;
	A[2][0] = -1;
	A[3][0] =  1;

	A[0][1] =  1;
	A[1][1] =  0;
	A[2][1] = -1;
	A[3][1] =  1;

	A[0][2] =  2;
	A[1][2] =  2;
	A[2][2] =  1;
	A[3][2] = -1;

	A[0][3] = -2;
	A[1][3] = -1;
	A[2][3] =  1;
	A[3][3] =  1;

}

void display() {
	std::cout << std::endl;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			std::cout << A[x][y] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}
//
//int main() {
//
//	int n = 4;
//
//	fillWithInput();
//
//
//	for (int j = 0; j < n-1; j++)
//	{
//		for (int i = j + 1 ; i < n; i++)
//		{
//			A[i][j] = A[i][j] / A[j][j];
//
//			for (int k = j + 1; k < 4; k++)
//			{
//				A[i][k] = A[i][k] - A[i][j] * A[j][k];
//			}
//		}
//	}
//
//
//	display();
//
//}