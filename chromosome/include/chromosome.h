#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_
#include<iostream>
const int POPSIZE = 50 ;     //种群数
class Chromosome{
    private:
        enum{ ALL_TYPE = 39};  //染色体标准
        float eval;
        float survive_rate;
        int code[ALL_TYPE];
        float add_eval;
        float x1;
        float x2;
        int num_Cross = 0;
        int num_Variation = 0.0;
    public:
        int generate;
        // Chromosome(float eval = 0.0,float sr= 0.0,int generate = 0,float ae= 0.0, float x1= 0.0, float x2= 0.0):eval(eval),survive_rate(sr),generate(generate),add_eval(ae),x1(x1),x2(x2){}
        Chromosome();  
        ~Chromosome(){};
        float getEval(){return eval;};
        float Judge(int *, int n1, int n2);
        int Decimal(int *A, int index,int length);
        friend std::ostream & operator<<(std::ostream &os, const Chromosome & chromosome);
        friend void Sort(Chromosome (&A)[POPSIZE]);
        friend void SurviveRate(Chromosome (&A)[POPSIZE], Chromosome & bestman);
        // friend void Initialize(Chromosome (&A)[POPSIZE], int num);  //对象数组的引用作为参数必须制定数组长度
        friend void Cross(Chromosome (&A)[POPSIZE], int p);  
        friend void Variation( Chromosome (&A)[POPSIZE], float P);
        Chromosome & operator=(const Chromosome & rs);
};


#endif