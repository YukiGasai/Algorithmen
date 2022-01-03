#include <iostream>
#include <cmath>
#include <time.h>
const double EulerConstant = std::exp(1.0);


int graph[6][6] = {
					{-1, 3 , 5 , 6 , 7 , 4},
					{ 3,-1 , 6 , 1 , 4 , 9},
					{ 5, 6 ,-1 , 4 ,10 , 8},
					{ 6, 1 , 4 ,-1 , 7 , 3},
					{ 7, 4 ,10 , 7 ,-1 , 5},
					{ 4, 9 ,8  , 3 , 5 ,-1}
};

int getRandomBetween(int min, int max, int ignore = -1) {
	int value = -1;
	do {
		value = rand() % (max - min + 1) + min;
	} while (value == ignore);
	return value;
}


int getWayLength(int* routes, int size) {
	int total = 0;
	int start = routes[0];
	for (int i = 1; i < size; i++)
	{
		int l = graph[start][routes[i]];
		if (l == -1)return 99999999;

		total += l;
		start = routes[i];
	}

	return total;
}

void swapArray(int* way,int size, int start, int end) {
	int* copy = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		copy[i] = way[i];
	}

	for (int i = start; i <= end; i++) {
		copy[i] = way[start + (end - i)];
	}

	
	for (int i = 0; i < size; i++)
	{
		way[i] = copy[i];
	}

	delete[] copy;
}

int main() {
	srand(time(nullptr));
	int smol = 999;

	for (int run = 0; run < 1000; run++) {

		int size = 7;
		int* way = new int[size];
		for (int i = 0; i < 7; i++)
		{
			way[i] = i;
		}
		way[6] = 0;


		float T = 100;
		int kurzeste = 100;

		while (T > 0.00001) {

			int currentLength = getWayLength(way, size);

			if (kurzeste > currentLength) {
				kurzeste = currentLength;
			}
			else
			{
				float dE = abs(currentLength - kurzeste);

				float p = pow(EulerConstant, -(dE / T));
				float r = getRandomBetween(0, 100) / 100;

				if (p > r) {
					kurzeste = currentLength;
				}
			}

			int a = getRandomBetween(0, 6);
			int b = getRandomBetween(0, 6, a);

			swapArray(way, 7, a, b);

			T = T / 2;
		}
		delete[] way;

		if (smol > kurzeste) {
			smol = kurzeste;
		}
	}

	std::cout << smol << std::endl;

}