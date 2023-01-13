#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;

}

void stat(const double data[] ,int N ,double output[])
{
    double AP,sum = 0;
    for(int i = 0;i < N;i++)
    {
        sum += data[i];
    }
    AP = sum/N;
    output[0] = AP;

    double Sumpow2 = 0,SD;
    for(int i = 0;i<N;i++)
    {
        Sumpow2 += pow(data[i],2); 
    }
    SD = sqrt((Sumpow2/N) - pow(AP,2));
    output[1] = SD; 

    double GM,Summul = 1,num = N;
    for(int i = 0;i<N;i++)
    {
        Summul = Summul * data[i];
    }
    GM = pow(Summul,1/num);
    output[2] = GM;

    double HM,sumdata = 0; 
    for(int i = 0;i<N;i++)
    {
        sumdata += 1/data[i]; 
    }
    HM = N/sumdata;
    output[3] = HM;

    double min = data[0],max = data[0];
    for(int i = 0;i<N;i++)
    {
        if(data[i] > max) max = data[i];
        if(data[i] < min) min = data[i];
    }
    output[4] = max;
    output[5] = min;
}