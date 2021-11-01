#include <iostream>



float* RegressionsGerade(float* inputDataX, float* inputDataY, int size){

	float xSum = 0;
	float ySum = 0;
	float xAvr = 0;
	float yAvr = 0;


	float xiyiSum = 0;
	float xixiSum = 0;

	for (int i = 0; i < size; i++)
	{
		xSum += inputDataX[i];
		ySum += inputDataY[i];

		xiyiSum += inputDataX[i] * inputDataY[i];
		xixiSum += inputDataX[i] * inputDataX[i];
	}

	xAvr = xSum / size;
	yAvr = ySum / size;

	float b = (xiyiSum - size * xAvr * yAvr) / (xixiSum - size * (xAvr * xAvr));

	float a = yAvr - b * xAvr;

	float* resultArray = new float[2]{ 0 };
	resultArray[0] = a;
	resultArray[1] = b;

	return resultArray;
}



int main()
{
	int size = 11;
	float* inputDataX = new float[size] { 0 };
	float* inputDataY = new float[size] { 7.7, 8.0, 7.9, 8.1, 8.3, 8.1, 7.9, 8.3, 8.5, 9.0, 9.2 };
										 
	for (int i = 0; i < size; ++i) {	  
		inputDataX[i] = i*10+ 1905;		  
	}									  


	float* resultArray = RegressionsGerade(inputDataX, inputDataY, size);


	std::cout << "a :" << resultArray[0] << std::endl;
	std::cout << "b :" << resultArray[1] << std::endl;

	return 0;
}
