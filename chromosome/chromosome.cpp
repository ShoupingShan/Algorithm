#include<iostream>
#include"include/chromosome.h"
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
static int numVariation = 0;
static int numCross = 0;
Chromosome::Chromosome(){
    eval = 0.0;
    survive_rate = 0.0;
    generate = 0;
    add_eval = 0.0;
    x1 = 0.0;
    x2 = 0.0;
    int randArray[Chromosome::ALL_TYPE];
    //随即初始化randArray
    for(int i = 0; i < Chromosome::ALL_TYPE; i++){
        randArray[i] = i;
        code[i] = 0;
    }
    for(int i = 0;i < Chromosome::ALL_TYPE;i++){
        int index = int(rand()%Chromosome::ALL_TYPE);
        int temp = randArray[index];
        randArray[index] = randArray[i];
        randArray[i] = temp;
    }
    //先从ALL_TYPE维特征中随机选择num个特征
    for(int i = 0;i < 20;i++)
        code[randArray[i]] = 1;
}

Chromosome& Chromosome::operator=(const Chromosome&rs){
    if(this==&rs)
        return *this;
    this->eval = rs.eval;
    this->survive_rate = rs.survive_rate;
    this->add_eval=rs.add_eval;
    this->x1 = rs.x1;
    this->x2 = rs.x2;
    this->generate = rs.generate;
    for(int i=0;i<Chromosome::ALL_TYPE;i++){
        this->code[i]=rs.code[i];
    }
    return *this;
}


int Chromosome::Decimal(int *A, int index,int length){
    int add = 0;
    for (int i = index + length-1; i >=index; i--){
        if (A[i] == 1){
            add += pow(2, index + length - 1-i);
        }
    }
    return add;
}

//A表示染色体，n1表示x1长度，n2表示x2长度
float Chromosome::Judge(int * A, int n1, int n2){
    const float PI = 3.141592654;
    int x1_int, x2_int;
    float x1_float, x2_float;
    x1_int = Decimal(A, 0, n1);
    x2_int = Decimal(A, n1, n2);
    x1_float = -3.0 + x1_int*(15.1 / 2097151);//2097151=2^21-1
    x2_float = 4.1 + x2_int*(1.7/262144);
    //262144 =2^18-1
    float temp = 21.5 + x1_float*sin(4 * PI*x1_float) + x2_float*sin(20 * PI*x2_float);
    return temp;
}
void SurviveRate(Chromosome (&population)[POPSIZE],  Chromosome & bestman){
    float add_rate = 0;
    for (int k = 0; k < POPSIZE; k++){
        population[k].eval = population[k].Judge(population[k].code, 21, 18); //成员函数没有this指针，需要指定具体对象
        add_rate += population[k].eval;
    }
    for (int k = 0; k < POPSIZE; k++){
        population[k].survive_rate = population[k].eval / add_rate;
        population[k].add_eval = add_rate;
    }
    Sort(population);
    if (/*population[0].eval>bestman.eval*/1){
        bestman = population[0];//bestman preserve method
        bestman.num_Cross = numCross;
        bestman.num_Variation = numVariation;
        //population[POPSIZE-1] = bestman;  //Put the bestman into new multiplication
        int m = bestman.Decimal(bestman.code, 0, 21);
        int n = bestman.Decimal(bestman.code, 21, 18);
        bestman.x1 = -3.0 + m*(15.1 / 2097151);//2097151=2^21-1
        bestman.x2 = 4.1 + n*(1.7 / 262144);//262144 =2^18-1
    }
}
// p->cross probability
void Cross(Chromosome (&population)[POPSIZE], int P){
    for(int i = 0;i<POPSIZE;i++)
        for(int j=0;j<POPSIZE;j++){
            if(i!=j){
                int p = rand()%P;
                if((p < population[i].survive_rate*P)&&(p < population[j].survive_rate*P)){
                    numCross++;
                    int index = rand() % Chromosome::ALL_TYPE;  //index->the index of cross point
                    for(int t = 0;t<index;t++){
                        int temp = population[i].code[t];
                        population[i].code[t] = population[j].code[t];
                        population[j].code[t] = temp;
                    }
                }
            }else{
                continue;
            }
        }
}
void Sort(Chromosome (&population)[POPSIZE]){
    for (int i = 0; i < POPSIZE; i++)
        for (int j = i + 1; j < POPSIZE; j++){
            if (population[j].survive_rate >= population[i].survive_rate){
                Chromosome temp = population[i];
                population[i] = population[j];
                population[j] = temp;
            }
        }
}
//重载<<运算符
std::ostream & operator<<(std::ostream &os, const Chromosome & chromosome){
    os<<"染色体编码：\n";
    for(int i = 0; i< chromosome.ALL_TYPE; i++){
        os<<chromosome.code[i]<<" ";
    }
    os<<"\n染色体经历了"<<chromosome.num_Cross<<"次交叉操作，"<<chromosome.num_Variation<<"次变异操作.";
    os<<"\033[31m\nx1= "<<chromosome.x1<<"\033[0m \033[34m x2= "<<chromosome.x2<<"\033[0m\n";
    os<<"\033[35m最大值为\033[34m"<<chromosome.eval<<"\033[0m\n";
    return os;
}

void Variation(Chromosome (&population)[POPSIZE], float P){
    for(int k = 0;k < POPSIZE; k++){
        if(rand()%100 < P * 100){
            numVariation++;
            int index = rand() % Chromosome::ALL_TYPE;
            population[k].code[index] = abs(population[k].code[index] - 1); //1->0,0->1  
        }
    }
    
}
