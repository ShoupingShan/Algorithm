#ifndef MULTIPLE_H_
#define MULTIPLE_H_
#include<iostream>
class Polynomial{
    private:
        float * an;
        int len;
        float x;
        float result;
    public:
        enum Mode{One, Two, Three, Four};
        Polynomial(int num,float x); 
        Polynomial();
        ~Polynomial();
        Polynomial(const Polynomial &);
        int length()const{return len;}
        Polynomial &operator =(const Polynomial &);
        float Solve(Mode,float x);
        float SolveResult()const{return result;}
};
#endif