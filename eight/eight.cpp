// eight.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

float f(float x, float y) {
    return x * x + y * y;
}

double ableitung1(float x, float y, int j) {
    double h = 0.000001;

    if (j == 0) {
        return (f(x + h, y) - f(x, y)) / h;
    }
    else {
        return (f(x, y+h) - f(x, y)) / h;
    }
  
}



float* Gradientenverfahren(float s)
{
    int dimension = 2;
    float* oldResult = new float[dimension];

    oldResult[0] = 1;
    oldResult[1] = 1;
    float oldAbs = 0;

    for (int i = 0; i < 10; i++)
    {
        float absolute = 0;
        for (int d = 0; d < dimension; d++)
        {
            float eee = ableitung1(oldResult[0], oldResult[1], d);
            oldResult[d] = oldResult[d] + s * -(eee);
            absolute += oldResult[d] * oldResult[d];
            std::cout << oldResult[d] << std::endl;
        }
        std::cout << std::endl;
        absolute = sqrt(absolute);
     
        if (abs(oldAbs - absolute) < 0.01) {
            return oldResult;
        }
        oldAbs = absolute;
    }
    return oldResult;
}



int main()
{
 
    Gradientenverfahren(0.3);





    std::cout << "Hello World!\n";
}
