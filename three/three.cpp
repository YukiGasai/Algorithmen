
#include <iostream>


float IntegralUntersumme(float a, float b, int hAnzahl) {


	float deltaX = abs(b - a) / hAnzahl;

	float result = 0;

	for (float x = a; x < b; x= x +deltaX)
	{
		result += x * x;
	}

    return deltaX * result;
}


float IntegralTrapezverfahren(float a, float b, int hAnzahl) {


	float deltaX = abs(b - a) / hAnzahl;

	float result = 0;

	for (float x = a; x < b; x = x + deltaX)
	{
		result += (x * x) + (x+deltaX)*(x+deltaX);
	}

	return deltaX/2 * result;
}


float IntegralSimpsonverfahren(float a, float b, int hAnzahl) {


	float deltaX = abs(b - a) / hAnzahl;

	float result = 0;

	int i = 0;
	for (float x = a;  x <= b; x = x + deltaX)
	{
		if (x == a || x == b)
		{
			result += x * x;
		}
		else if (i % 2 == 0) {
			result += 2 * (x * x);
		}
		else {
			result += 4 * (x * x);
		}
		i++;
		
	}

	return deltaX / 3 * result;
}




int main()
{
    std::cout << "Rechteckverfahren: " << IntegralUntersumme(0, 2, 4) << std::endl;

	std::cout << "Trapezverfahren: " << IntegralTrapezverfahren(0, 2, 4) << std::endl;

	std::cout << "Simsonverfahren: " << IntegralSimpsonverfahren(0, 2, 4) << std::endl;

	std::cout << "Simsonverfahren: " << IntegralSimpsonverfahren(1, 2, 4) << std::endl;

	return 0;
}
