#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "Library.cpp"
using namespace std;

double f(float x){
    return x/(1+x);
}

int main(){
    float arrX[5][4];
    for(int i = 0;i<5;i++){
        for(int j =0;j<4;j++){
            if(j == 0){
                arrX[0][j] = 10;
                arrX[1][j] = 25;
                arrX[2][j] = 125;
                arrX[3][j] = 1000;
                arrX[4][j] = 5000;
            }
            else if (j == 1){
                arrX[i][j] = Midpoint(f,1.0,3.0,arrX[i][0]);
            }
            else if(j == 2){
                arrX[i][j] = Trapezoidal(f,1.0,3.0,arrX[i][0]);
            }
            else arrX[i][j] = Simpsons(f,1.0,3.0,arrX[i][0]);
        }
    }
    cout << "N  " << "   M   " << "   T  " << "   S " << endl;
    for(int i = 0;i<5;i++){
        cout << arrX[i][0] << " " << arrX[i][1] << " "  << arrX[i][2] << " " << arrX[i][3] << endl;
    }
    cout << "***********" << endl;
    /*
    N     M      T     S
    10 1.30716 1.23123 1.25685
    25 1.3069 1.27675 1.26692
    125 1.30685 1.30085 1.29886
    1000 1.30685 1.3061 1.30635
    5000 1.30685 1.3067 1.30675
    */
    return 0;
}


