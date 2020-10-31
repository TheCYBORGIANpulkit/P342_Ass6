#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "Library.cpp"
using namespace std;

double f(float x){
    double y = pow(x,2);
    return exp(-y);
}

double f2(float x){
    double y = pow(x,2);
    return (-2)*(exp(-y))*(1 - 2*y);
}

double f4(float x){
    double w = 16*pow(x,4) - 48*pow(x,2) + 12;
    double y = pow(x,2);
    return w*(exp(-y));
}

float Counter_Midpointer(float a,float b, float N){
    float e = pow(b - a,3);
    float g = abs(f2(0));
    for(int i =0;i<1000;i++){
        float f = 24*(pow(N,2));
        float h = e/f;
        if(((e/f)*g) > 0.001){
            N = N + 1;
        }
        else return ceil(N);
    }
}

int Counter_Trapezoidal(float a,float b, int T){
    float e = pow(b - a,3);
    float g = abs(f2(0));
    for(int i =0;i<1000;i++){
        float f = 12*(pow(T,2));
        float h = e/f;
        if(((e/f)*g) > 0.001){
            T = T + 1;
        }
        else return ceil(T);
    }
}

int Counter_Simpsons(float a,float b, int S){
    float e = pow(b - a,5);
    float g = abs(f4(0.959));
    for(int i =0;i<1000;i++){
        float f = 180*(pow(S,4));
        float h = e/f;
        if(((e/f)*g) > 0.001){
            S = S + 2;
        }
        else return ceil(S);
    }
}

int main(){

    int N = Counter_Midpointer(0,1,1);
    cout << "Integration for counter N " << N  <<" = " << Midpoint(f,0,1.0,N) << endl;
    int T = Counter_Trapezoidal(0,1,1);
    cout << "Integration for counter T " << T << " = " << Trapezoidal(f,0,1.0,T) << endl;
    int S = Counter_Simpsons(0,1,2);
    cout <<"Integration for counter S " << S << " = " << Simpsons(f,0,1.0,S) << endl;
    return 0;
    /*
    Integration for counter N 10 = 0.747131
    Integration for counter T 13 = 0.732312
    Integration for counter S 4 = 0.716199
    */

}

