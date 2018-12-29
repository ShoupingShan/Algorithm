#include<iostream>
#include"include/matrix.h"
#include<ctime>
#include<fstream>
#include<cmath>
using namespace std;
#define CYCLES 11
int main(){
    clock_t start, finish;
    ofstream fout("time.txt");
    Matrix matrix_A[CYCLES]={
        Matrix(pow(2,2)),
        Matrix(pow(2,3)),
        Matrix(pow(2,4)),
        Matrix(pow(2,5)),
        Matrix(pow(2,6)),
        Matrix(pow(2,7)),
        Matrix(pow(2,8)),
        Matrix(pow(2,9)),
        Matrix(pow(2,10)),
        Matrix(pow(2,11)),
        Matrix(pow(2,12))
    };
    Matrix matrix_B[CYCLES]={
        Matrix(pow(2,2)),
        Matrix(pow(2,3)),
        Matrix(pow(2,4)),
        Matrix(pow(2,5)),
        Matrix(pow(2,6)),
        Matrix(pow(2,7)),
        Matrix(pow(2,8)),
        Matrix(pow(2,9)),
        Matrix(pow(2,10)),
        Matrix(pow(2,11)),
        Matrix(pow(2,12))
    };
    Matrix matrix_C[CYCLES]={
        Matrix(pow(2,2)),
        Matrix(pow(2,3)),
        Matrix(pow(2,4)),
        Matrix(pow(2,5)),
        Matrix(pow(2,6)),
        Matrix(pow(2,7)),
        Matrix(pow(2,8)),
        Matrix(pow(2,9)),
        Matrix(pow(2,10)),
        Matrix(pow(2,11)),
        Matrix(pow(2,12))
    };
    double timeTable[CYCLES][3];
    for(int i = 0;i < CYCLES;i++){
            //cout<<matrix_C[i];
            start=clock();
            matrix_A[i].Normal_Multiple(matrix_A[i],matrix_B[i],matrix_C[i]);
            finish=clock();
            timeTable[i][0]=(double)(finish-start)/CLOCKS_PER_SEC;
            cout<<"Round    "<<i+1<<"    Mode 1 costs   "<<timeTable[i][0]<<"   seconds!"<<endl;
            //cout<<matrix_C[i];
            fout<<(double)(finish-start)<<" ";
            start=clock();
            matrix_A[i].call_divide_and_conquer(matrix_A[i].getNum(), matrix_A[i],matrix_B[i],matrix_C[i]);
            finish=clock();
            timeTable[i][1]=(double)(finish-start)/CLOCKS_PER_SEC;
            cout<<"Round    "<<i+1<<"    Mode 2 costs   "<<timeTable[i][1]<<"   seconds!"<<endl;
            //cout<<matrix_C[i];
            fout<<(double)(finish-start)<<" ";
            start=clock();
            matrix_A[i].call_strassen(matrix_A[i].getNum(), matrix_A[i],matrix_B[i],matrix_C[i]);
            finish=clock();
            timeTable[i][2]=(double)(finish-start)/CLOCKS_PER_SEC;
            cout<<"Round    "<<i+1<<"    Mode 3 costs   "<<timeTable[i][2]<<"   seconds!"<<endl;
            //cout<<matrix_C[i];
            fout<<(double)(finish-start)<<" ";
        fout<<endl;
        }
        fout.close();
    return 0;
}
