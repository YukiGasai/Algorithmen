// six.cpp : Diese Datei enthält die Funytion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

#include <limits>



void printMatrix(float** matrix, int size) {
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int y = 0; y < size; y++)
        {
            std::cout << matrix[y][i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void prinVector(float* vector, int size) {
    std::cout << std::endl;
        for (int y = 0; y < size; y++)
        {
            std::cout << vector[y] <<  std::endl;
        }   
        std::cout << std::endl;
}



//Gibt L als Rückgabewert und R wird in A gespeichert
float** getLRMatrix(float** A, int size) {

    static float** L = new float* [size];
    for (int i = 0; i < size; ++i) {
        L[i] = new float[size];
    }

    //Fülle L Matrix mit der DiagonalMatrix auf bevor ergebisse gespeichert werden
    for (int i = 0; i < size; ++i) {
        for (int y = 0; y < size; y++)
        {
            if (i == y) {
                L[i][y] = 1;
            }
            else {
                L[i][y] = 0;
            }
        }
    }

  

    //1. LR Zerlegung
    for (int x = 0; x < size; x++)
    {
        for (int y = x+1; y < size; y++)
        {
    
            float divider = A[x][y] / A[x][x];
            L[x][y] = divider;
/*
            std::cout << "A[" << x << "][" << y << "] " << A[x][y] << std::endl;
            std::cout << "A[" << x << "][" << x << "] " << A[x][x] << std::endl;
            std::cout << "divider " << divider << std::endl;
*/

            for (int i = 0; i < size; i++)
            {
                A[i][y] = A[i][y] - divider * A[i][x];
            }

/*
            printMatrix(L, size);
            printMatrix(A, size);
            std::cout << "------------------------------------" << std::endl;
*/
        }
    }
//    printMatrix(L, 3);

    return L;
}


float* Vorwardssubstutution(float** L, float* B, int size) {
    static float* Y = new float[size];

    for (int y = 0; y < size; y++)
    {
        float leftSum = 0;
        for (int x = 0; x < size; x++)
        {
            if (x < y) {
                leftSum += L[x][y] * Y[x];
                //std::cout << x << " " << y << std::endl;
            }
        }
      
        Y[y] = B[y] - leftSum;
        //std::cout << Y[y] << "    " << y << std::endl;

    }
    return Y;
}


float* RuckSubstutution(float** R, float* Y, int size) {
    static float* X = new float[size];

    for (int y = size-1; y >= 0; y--)
    {
        float leftsum = 0;
        for (int x = 0; x < size; x++)
        {
            if (y < x) {
                leftsum += R[x][y] * X[x];
            }
        }
        X[y] = (Y[y] - leftsum) / R[y][y];

    }
    return X;
}


float* solveMain(float** A, float* B, int size) {

    float* X = new float[size];
    X[0] = 0;
    X[1] = 1;
    X[2] = 2;

    float** L = getLRMatrix(A, size);

    float* Y = Vorwardssubstutution(L, B, size);
    X = RuckSubstutution(A, Y, size);
    return X;
}

int* Zeilenpivotisierung(float** A, float* B,int size) {

    static int* resultOrder = new int[size];
    for (int i = 0; i < size; i++)
    {
        resultOrder[i] = i;
    }

    for (int x = 0; x < size; x++)
    {
        float maxValue = 0;
        int maxIndex = x;
        for (int y = x; y < size; y++)
        {
            if (y == x) {
                maxValue = A[x][y];
            }

            if (maxValue < A[x][y]) {
                maxValue = A[x][y];
                maxIndex = y;
            }
        }


        for (int i = x; i < size; i++)
        {
          
            float copy = A[i][maxIndex];
            A[i][maxIndex] = A[i][i];
            A[i][i] = copy;
        
            float copyB = B[maxIndex];
            B[maxIndex] = B[i];
            B[i] = copyB;

            float copyResultOrder = resultOrder[maxIndex];
            resultOrder[maxIndex] = resultOrder[i];
            resultOrder[i] = copyResultOrder;  
        }
    }

    return resultOrder;
}

int* Pivotisierung(float** A, float* B,int size) {
    int* resultOrder = Zeilenpivotisierung(A, B, size);
    return resultOrder;
}

float* UndoPivotisierung(float* X, int* resultOrder, int size) {
    

    prinVector(X, 3);

    static float* result = new float[size];
    for (int i = 0; i < size; i++)
    {   
        result[i] = X[resultOrder[i]];
    }
    return result;
}

int main()
{
    /*
    int size = 3;
    float** A = new float* [size];
    for (int i = 0; i < size; ++i) {
        A[i] = new float[size];
    }

    A[0][0] = 3;
    A[1][0] = 2;
    A[2][0] = 1;
    A[0][1] = 6;
    A[1][1] = 6;
    A[2][1] = 3;
    A[0][2] = 9;
    A[1][2] = 10;
    A[2][2] = 6;

    float* B = new float[size];
    B[0] = 2;
    B[1] = 3;
    B[2] = 5;
    */
    int size = 4;
    float** A = new float* [size];
    for (int i = 0; i < size; ++i) {
        A[i] = new float[size];
    }

    A[0][0] = -1;
    A[1][0] = 1;
    A[2][0] = -1;
    A[3][0] = 1;

    A[0][1] = 1;
    A[1][1] = 0;
    A[2][1] = -1;
    A[3][1] = 1;

    A[0][2] = 2;
    A[1][2] = 2;
    A[2][2] = 1;
    A[3][2] = -1;

    A[0][3] = -2;
    A[1][3] = -1;
    A[2][3] = 1;
    A[3][3] = 1;

    float* B = new float[size];
    B[0] = 1;
    B[1] = 2;
    B[2] = 3;
    B[3] = 4;

    int* resultOrder = Pivotisierung(A, B, size);
 
    float* result = solveMain(A, B, size);
   

    prinVector(result, size);

    //float* finalResult =  UndoPivotisierung(result, resultOrder, size);

    //prinVector(finalResult, size);

}
