#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int size, double B[]){
    
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += A[i];
    }
    B[0] = sum / size;

    double variance = 0;
    for(int i = 0; i < size; i++){
        variance += pow((A[i] - B[0]), 2);
    }
    B[1] = sqrt((variance / size));

    double product = 1;
    for(int i = 0; i < size; i++){
        product *= A[i];
    }
    B[2] = pow(product,(1.0 / size));

    double reciSum = 0;
    for(int i = 0; i < size; i++){
        reciSum += 1 / A[i];
    }
    B[3] = size / reciSum;

    double max = A[0];
    double min = A[0];
    for(int i = 0; i < size; i++){
        if(A[i] > max){
            max = A[i];
        }else if(A[i] < min){
            min = A[i];
        }
    }
    B[4] = max;
    B[5] = min;
}