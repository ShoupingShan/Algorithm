#include"include/matrix.h"
#include<cstdlib>
#include<iostream>
#include<ctime>
Matrix::Matrix(){
    this->N = 1;
    this->data = new double*[1];
    this->data[0] = new double[1];
    this->data[0][0] = 0.0;
    //std::cout<<"Matrix    "<<"1*1"<<"    is initialized!\n";
}
Matrix::Matrix(int n){
    this->N = n;
    this->data = new double*[this->N];
    for(int i = 0;i<this->N;i++)
        this->data[i] = new double[this->N];
    std::srand((unsigned)std::time(0));
    for(int i=0;i<this->N;i++)
        for(int j=0;j<this->N;j++){
            this->data[i][j]= (double)(rand()/(double)RAND_MAX);
        }
    //std::cout<<"Matrix    "<<N<<"*"<<N<<"    is initialized!\n";
}
Matrix::Matrix(int n,double init){
    this->N = n;
    this->data = new double*[this->N];
    for(int i = 0;i<this->N;i++)
        this->data[i] = new double[this->N];
    for(int i=0;i<this->N;i++)
        for(int j=0;j<this->N;j++){
            this->data[i][j]= init;
        }
    //std::cout<<"Matrix 0.0   "<<N<<"*"<<N<<"    is initialized!\n";
}
Matrix & Matrix::operator=(const Matrix &st){
    if(this == &st)
        return *this;
    for(int i=0;i<this->N;i++)
        delete [] this->data[i];
    delete [] this->data;
    this->N = st.N;
    this->data = new double*[this->N];
    for(int i = 0;i<N;i++)
        this->data[i] = new double[this->N];
    for(int i=0;i<this->N;i++)
        for(int j=0;j<this->N;j++)
            this->data[i][j]=st.data[i][j];
    return *this;
}
Matrix::~Matrix(){
    for(int i=0;i<this->N;i++)
        delete [] this->data[i];
    delete [] this->data;
}
void Matrix::add(int n, const Matrix &A, const Matrix &B, Matrix &R){
    for(int i=0; i<n; i++)
        for(int j=0;j<n;j++)
            R.data[i][j] = A.data[i][j] + B.data[i][j];
}
void Matrix::sub(int n, const Matrix &A, const Matrix &B, Matrix &R){
    for(int i=0; i<n; i++)
        for(int j=0;j<n;j++)
            R.data[i][j] = A.data[i][j] - B.data[i][j];
}
void Matrix::multiple(const Matrix &A,const Matrix &B,Matrix &C){
    for(int i=0;i<2;i++)
        for(int j =0;j<2;j++){
            C.data[i][j] = 0.0;
            for(int t = 0;t <2;t++){
                C.data[i][j] = C.data[i][j] + A.data[i][t]*B.data[t][j];
            }
        }
}
/*
void Matrix::strassen(int n, Matrix &A, Matrix &B, Matrix &C){
    double **A11,**A12,**A21,**A22;
    double **B11,**B12,**B21,**B22;
    double **C11,**C12,**C21,**C22;
    double **AA,**BB;
    double **M1,**M2,**M3,**M4,**M5,**M6,**M7;
    A11 = new double*[this->N];  //Memory malloc step
    A12 = new double*[this->N];
    A21 = new double*[this->N];
    A22 = new double*[this->N];
    B11 = new double*[this->N];
    B12 = new double*[this->N];
    B21 = new double*[this->N];
    B22 = new double*[this->N];
    C11 = new double*[this->N];
    C12 = new double*[this->N];
    C21 = new double*[this->N];
    C22 = new double*[this->N];
    A11 = new double*[this->N];
    AA  = new double*[this->N];
    BB  = new double*[this->N];
    M1  = new double*[this->N];
    M2  = new double*[this->N];
    M3  = new double*[this->N];
    M4  = new double*[this->N];
    M5  = new double*[this->N];
    M6  = new double*[this->N];
    M7  = new double*[this->N];
    for(int i=0;i<this->N;i++){
        A11[i] = new double[this->N];
        A12[i] = new double[this->N];
        A21[i] = new double[this->N];
        A22[i] = new double[this->N];
        B11[i] = new double[this->N];
        B12[i] = new double[this->N];
        B21[i] = new double[this->N];
        B22[i] = new double[this->N];
        C11[i] = new double[this->N];
        C12[i] = new double[this->N];
        C21[i] = new double[this->N];
        C22[i] = new double[this->N];
        A11[i] = new double[this->N];
        AA[i]  = new double[this->N];
        BB[i]  = new double[this->N];
        M1[i]  = new double[this->N];
        M2[i]  = new double[this->N];
        M3[i]  = new double[this->N];
        M4[i]  = new double[this->N];
        M5[i]  = new double[this->N];
        M6[i]  = new double[this->N];
        M7[i]  = new double[this->N];
    }
    if(n==2){
        multiple(A, B, C);
    }else{
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                A11[i][j] = A.data[i][j];
                A12[i][j] = A.data[i][j+n/2];
                A21[i][j] = A.data[i+n/2][j];
                A22[i][j] = A.data[i+n/2][j+n/2];
                B11[i][j] = B.data[i][j];
                B12[i][j] = B.data[i][j+n/2];
                B21[i][j] = B.data[i+n/2][j];
                B22[i][j] = B.data[i+n/2][j+n/2];
            }
        }
        sub(n/2, B12, B22, BB);
    }
}
*/
void Matrix::Normal_Multiple( Matrix &A, Matrix &B, Matrix &C){
    for(int i=0;i<A.N;i++)
        for(int j =0;j<A.N;j++){
            C.data[i][j] = 0.0;
            for(int t = 0;t <A.N;t++){
                C.data[i][j] = C.data[i][j] + A.data[i][t]*B.data[t][j];
            }
        }
}
void Matrix::call_divide_and_conquer(int n, Matrix &A, Matrix &B, Matrix &C){
    Matrix array[20]={
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0),
        Matrix(N,0.0)
    };
    Matrix::Divide_and_conquer(N,A,B,C,array);
}
void Matrix::Divide_and_conquer(int n, Matrix &A, Matrix &B, Matrix &C,Matrix (&array)[20]){
    Matrix A11(N,0.0);
    Matrix A12(N,0.0);Matrix A21(N,0.0);Matrix A22(N,0.0);Matrix B11(N,0.0);Matrix B12(N,0.0);Matrix B21(N,0.0);Matrix B22(N,0.0);
    Matrix C11(N,0.0);Matrix C12(N,0.0);Matrix C21(N,0.0);Matrix C22(N,0.0);
    Matrix M1(N,0.0);Matrix M2(N,0.0);Matrix M3(N,0.0);Matrix M4(N,0.0);Matrix M5(N,0.0);Matrix M6(N,0.0);Matrix M7(N,0.0);Matrix M8(N,0.0);
    if(n==2){
        multiple(A, B, C);
    }else{
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                A11.data[i][j] = A.data[i][j];
                A12.data[i][j] = A.data[i][j+n/2];
                A21.data[i][j] = A.data[i+n/2][j];
                A22.data[i][j] = A.data[i+n/2][j+n/2];
                B11.data[i][j] = B.data[i][j];
                B12.data[i][j] = B.data[i][j+n/2];
                B21.data[i][j] = B.data[i+n/2][j];
                B22.data[i][j] = B.data[i+n/2][j+n/2];
            }
        }
        Divide_and_conquer(n / 2, A11, B11, M1); //M1=A11B11
        Divide_and_conquer(n / 2, A12, B21, M2); //M2=A12B21
        Divide_and_conquer(n / 2, A11, B12, M3); //M3=A11B12
        Divide_and_conquer(n / 2, A12, B22, M4); //M4=A12B22
        Divide_and_conquer(n / 2, A21, B11, M5); //M5=A21B11
        Divide_and_conquer(n / 2, A22, B21, M6); //M6=A22B21
        Divide_and_conquer(n / 2, A21, B12, M7); //M7=A21B12
        Divide_and_conquer(n / 2, A22, B22, M8); //M8=A22B22
        //C11 = M1 + M2 
        add(n / 2, M1, M2, C11);
        //C12 = M3 + M4
        add(n / 2, M3, M4, C12);
        //C21 = M5 + M6
        add(n / 2, M5, M6, C21);
        //C22 = M7 + M8
        add(n / 2, M7, M8, C22);
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n/2;j++){
                C.data[i][j] = C11.data[i][j];
                C.data[i][j+n/2] = C12.data[i][j];
                C.data[i+n/2][j] = C21.data[i][j];
                C.data[i+n/2][j+n/2] = C22.data[i][j];
            }
    }
}
void Matrix::Strassen(int n, Matrix &A, Matrix &B, Matrix &C){
    
    if(n==2){
        multiple(A, B, C);
    }else{
        Matrix A11(N,0.0);Matrix A12(N,0.0);Matrix A21(N,0.0);Matrix A22(N,0.0);Matrix B11(N,0.0);Matrix B12(N,0.0);Matrix B21(N,0.0);Matrix B22(N,0.0);
        Matrix C11(N,0.0);Matrix C12(N,0.0);Matrix C21(N,0.0);Matrix C22(N,0.0);Matrix AA(N,0.0);Matrix BB(N,0.0);
        Matrix M1(N,0.0);Matrix M2(N,0.0);Matrix M3(N,0.0);Matrix M4(N,0.0);Matrix M5(N,0.0);Matrix M6(N,0.0);Matrix M7(N,0.0);
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                A11.data[i][j] = A.data[i][j];
                A12.data[i][j] = A.data[i][j+n/2];
                A21.data[i][j] = A.data[i+n/2][j];
                A22.data[i][j] = A.data[i+n/2][j+n/2];
                B11.data[i][j] = B.data[i][j];
                B12.data[i][j] = B.data[i][j+n/2];
                B21.data[i][j] = B.data[i+n/2][j];
                B22.data[i][j] = B.data[i+n/2][j+n/2];
            }
        }
        sub(n/2, B12, B22, BB);
        Strassen(n/2, A11,BB, M1); //M1=A11(B12-B22)
        add(n / 2, A11, A12, AA);
        Strassen(n / 2, AA, B22, M2); //M2=(A11+A12)B22
        add(n / 2, A21, A22, AA);
        Strassen(n / 2, AA, B11, M3); //M3=(A21+A22)B11
        sub(n / 2, B21, B11, BB);
        Strassen(n / 2, A22, BB, M4); //M4=A22(B21-B11)
        add(n / 2, A11, A22, AA);
        add(n / 2, B11, B22, BB);
        Strassen(n / 2, AA, BB, M5); //M5=(A11+A22)(B11+B22)
        sub(n / 2, A12, A22, AA);
        add(n / 2, B21, B22, BB);
        Strassen(n / 2, AA, BB, M6);  //M6=(A12-A22)(B21+B22)
        sub(n / 2, A11, A21, AA);
        add(n / 2, B11, B12, BB);
        Strassen(n / 2, AA, BB, M7); //M7=(A11-A21)(B11+B12)

        //C11 = M5 + M4 - M2 + M6
        add(n / 2, M5, M4, AA);
        sub(n / 2, M6, M2, BB);
        add(n / 2, AA, BB, C11);

        //C12 = M1 + M2
        add(n / 2, M1, M2, C12);

        //C21 = M3 + M4
        add(n / 2, M3, M4, C21);

        //C22 = M5 + M1 - M3 - M7
        sub(n / 2, M5, M3, AA);
        sub(n / 2, M1, M7, BB);
        add(n / 2, AA, BB, C22);
        for(int i=0;i<n/2;i++)
            for(int j=0;j<n/2;j++){
                C.data[i][j] = C11.data[i][j];
                C.data[i][j+n/2] = C12.data[i][j];
                C.data[i+n/2][j] = C21.data[i][j];
                C.data[i+n/2][j+n/2] = C22.data[i][j];
            }
    }
}

std::ostream & operator<<(std::ostream & os, const Matrix &st){
    for(int i=0;i<st.N;i++){
        for(int j=0;j<st.N;j++)
            std::cout<<st.data[i][j]<<" ";
        std::cout<<std::endl;
    }
        
}