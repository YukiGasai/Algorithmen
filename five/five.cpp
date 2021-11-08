#include <iostream>



float fx(float x) {
	return x * x;
}

float EulerCauchy(float h, int loops) {

	float oldy = 1;
	float oldx = 0;

	for (float x = 0; x < loops; x+=h)
	{
		float yi1 = (2 * oldy * oldx) * h + oldy;

		float xi1 = oldx + h;
		
		oldy = yi1;
		oldx = xi1;
	}

	std::cout << oldy << std::endl;
	return oldy;
}

float RungeKutta2(float s, int loops) {
	float oldy = 1;
	float oldx = 0;

	for (float x = 0; x < loops; x += s)
	{

		float k1 = 2 * oldx * oldy;
		float k2 = 2 * (oldx + s)* (oldy + s * k1);


		float dy = s / 2 * (k1 + k2);

		oldy = oldy+dy;
		oldx = oldx+s;
	}

	std::cout << oldy << std::endl;
	return oldy;
}



float RungeKutta4(float s, int loops) {
	float oldy = 1;
	float oldx = 0;

	for (float x = 0; x < loops; x += s)
	{

		float k1 = 2 * oldx * oldy;
		float k2 = 2 * (oldx + s / 2) * (oldy + s * k1 / 2);
		float k3 = 2 * (oldx + s / 2) * (oldy + s * k2 / 2);
		float k4 = 2 * (oldx + s) * (oldy + s * k3);

		float dy = s/6 * (k1 + 2*k2 + 2*k3+k4);

		oldy = oldy + dy;
		oldx = oldx + s;
	}

	std::cout << oldy << std::endl;
	return oldy;
}


int main()
{
	EulerCauchy(0.001, 4);

	RungeKutta2(0.001, 4);

	RungeKutta4(0.001, 4);
}
