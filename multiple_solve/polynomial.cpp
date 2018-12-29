#include<cmath>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"include/polynomial.h"
float mypow(float x, int n){
    float result = 1.0;
    for(int i=0;i<n;i++)
        result*=x;
    return result;
}
float solve_one(float * an, float x, int len){
    float result = 0.0;
    for(int i = 0;i <len; i++)
        result += an[i]*mypow(x,i);
    // std::cout<<"Method 1 is called!\n";
    //std::cout<<result<<std::endl;
    return result;
}
float solve_two(float * an, float x, int len){
    float result = an[0];
    for(int i=1;i<len;i++)
        result += an[i]*mypow(x,i);
    // std::cout<<"Method 2 is called!\n";
    //std::cout<<result<<std::endl;
    return result;
}
float solve_three(float * an, float x, int len){
    float result = an[0],temp=1;
    for(int i=1;i<len;i++){
        temp *= x;
        result += an[i]*temp;
    }
    // std::cout<<"Method 3 is called!\n";
    //std::cout<<result<<std::endl;
    return result;
}
float solve_four(float * an, float x, int len){
    float result = an[len - 1];
    for(int i=1;i<len;i++){
        result *= x;
        result += an[len-i-1];
    }
    //std::cout<<result<<std::endl;
    return result;
}

Polynomial::Polynomial(int num,float x){
    len = num;
    an = new float[len];
    result = 0.0;
    std::srand((unsigned)std::time(0)); 
    for(int i = 0; i < len;i++ ) 
         an[i] = (float)(rand()/(double)RAND_MAX);
    //std::cout<<"Polynomial("<<num<<") is initialized!\n";
}
float Polynomial::Solve(Mode mode,float x){
    switch(mode){
        case One:
            result = solve_one(an, x, len);
            break;
        case Two:
            result = solve_two(an, x, len);
            break;
        case Three:
            result = solve_three(an, x, len);
            break;
        case Four:
            result = solve_four(an, x, len);
            break;
        default:
            std::cout<<"Do not give correct Mode parameter.\n";
    }
    return result;
}
Polynomial::Polynomial(){
    an = new float[1];
    an[0] = 0.000;
    len = 1;
}
Polynomial::Polynomial(const Polynomial & st){
    len = st.len;
    an = new float[len];
    for(int i = 0;i<len;i++){
        an[i]=st.an[i];
    }
}
Polynomial::~Polynomial(){
    delete []an;
}
Polynomial & Polynomial::operator=(const Polynomial & st){
    if(this == &st)
        return *this;
    delete []an;
    len = st.len;
    an = new float[len];
    for(int i = 0;i<len;i++){
        an[i]=st.an[i];
    }
    return *this;
}

