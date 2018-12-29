#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
class Matrix{
    private:
        int N;  //Matrix=n*n,where  n is 2^x
        double **data;
    public:
        Matrix();     
        Matrix(int N);
        Matrix(int n,double init);
        ~Matrix();
        Matrix & operator=(const Matrix &);  //赋值构造函数
        void add(int n, const Matrix &A,const Matrix &B,Matrix &R);
        void sub(int n, const Matrix &A,const Matrix &B,Matrix &R);
        void multiple(const Matrix &A,const Matrix &B, Matrix &C);
        void Normal_Multiple(Matrix &A, Matrix &B, Matrix &C);
        void call_divide_and_conquer(int n, Matrix &, Matrix &, Matrix &);
        //void Strassen(int n, Matrix &, Matrix &, Matrix &);
        void Divide_and_conquer(int n, Matrix &, Matrix &, Matrix &, Matrix (&array)[20]);
        // void Divide_and_conquer(int n, Matrix &, Matrix &, Matrix &);
        void call_strassen(int n, Matrix &, Matrix &, Matrix &);
        void Strassen(int n, Matrix &, Matrix &, Matrix &, Matrix (&array)[21]);
        int getNum(){return N;}
        friend bool operator ==(const Matrix &st1, const Matrix &st2);
        friend std::ostream & operator<<(std::ostream & os, const Matrix &st);
};
#endif