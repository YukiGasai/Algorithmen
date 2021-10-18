#include <iostream>
#include <cmath>
#include <list>

//n te Wurzel von a ziehen
float calcWurzel(int n, int a) {
    float oldResult = 1;

    while (true) {
     
        float result = ((n - 1) * pow(oldResult, n) + a) / (n * pow(oldResult, n - 1));

        float diff = result - oldResult;

        diff = abs(diff);

        if (diff < 0.001) return result;

        oldResult = result;
    }
}



//Alle Primzahlen von 1 bis n zurück geben
void getPrime(int n) {

    int* list;
    list = new int[n+1] {0};

    
    for (int i = 2; i <= n; i++) {
        list[i] = i;
    }


    for (int i = 2; i < calcWurzel(2, n); i++)
    {
        for (int k = i; k <= n / i; k++)
        {
            if (i * k <= n) {
                list[i * k] = 0;
            }

        }
    }


    for (int i = 0; i <= n; i++) {
        if (list[i] != 0) {
            std::cout << list[i] << std::endl;
        }
    }

}



int ggT(int a, int b) {
    int clone;
    if (a < b) {
        clone = b;
        b = a;
        a = clone;
    }

    int h;
    while (b != 0) {
        h = a % b;
        a = b;
        b = h;
        std::cout << "TEST" << std::endl;
    }

    return a;


}


int main()
{

    std::cout << ggT(25, 15);

   //int n = 3;
   //int a = 16;
   //std::cout << calcWurzel(n, a);
   //getPrime(100);
}
