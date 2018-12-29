#include<iostream>
#include<ctime>
#include"include/polynomial.h"
#include<fstream>
using namespace std;
#define X 1.000001
#define N 12
int main(){
    clock_t start,finish;
    ofstream fout("time.txt");
    Polynomial poly[N]={
        Polynomial(10,X),
        Polynomial(50,X),
        Polynomial(100,X),
        Polynomial(150,X),
        Polynomial(200,X),
        Polynomial(300,X),
        Polynomial(400,X),
        Polynomial(500,X),
        Polynomial(10000,X),
        Polynomial(20000,X),
        Polynomial(50000,X),
        Polynomial(100000,X)
    };
    double timeTable[N][4],compareTable[N][4];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < 4;j++){
            start=clock();
            poly[i].Solve(Polynomial::Mode(j),X);  //transform enum to int 
            finish=clock();
            timeTable[i][j]=(double)(finish-start)/CLOCKS_PER_SEC;
            compareTable[i][j] = poly[i].SolveResult();
            cout<<"Round    "<<i+1<<"    Mode    "<<j+1<<"    costs   "<<timeTable[i][j]<<"   seconds!"<<endl;
            fout<<(double)(finish-start)/CLOCKS_PER_SEC<<" ";
        }
        fout<<endl;
        }
        fout.close();
    return 0;
}
