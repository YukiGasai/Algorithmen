#include <iostream>

//Berechnung von Pi über das verdoppeln der Ecken eines n Echks um es an einen Kreis anzupassen
double Achiments() {

	double pi = 0;
	double old = 2;
	for (int n = 2; n <= 536870912; n=n*2) {

		double newValue = sqrt((old * old) / (2 + 2 * sqrt(1 - (old * old / 4))));

		pi = n * newValue;

		old = newValue;

		std::cout << "N " << n << "    Pi " << pi << std::endl;
		
	}
	return pi;
}





int main()
{
	std::cout.precision(17);

	Achiments();
}
