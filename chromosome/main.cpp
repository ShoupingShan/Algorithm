#include<ctime>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include"include/chromosome.h"

using namespace std; 
int FIRST_TYPE = 20;   //初代显性形状数目
float P_CHNAGE = 0.05;  //变异概率
int MAX_GENGERATION = 5000;
Chromosome bestman;
int main(){
    ofstream fout("nobestman.txt");
    srand((unsigned)time(NULL));
    Chromosome population[POPSIZE]{bestman};
    //cout<<population[0]<<endl<<population[1]<<endl;
    clock_t start, finish;
    int counter = 0;
    start = clock();
    // Initialize(population,  FIRST_TYPE);
    for(int i =0;i<MAX_GENGERATION;i++){
        counter ++;
        for(int i =0;i<POPSIZE;i++)
            population[i].generate = counter;
        SurviveRate(population, bestman);
        Variation(population, P_CHNAGE);
        Cross(population,1000);
        fout<<bestman.getEval()<<" ";
        // if(i%100 == 0)
        //     fout<<endl;
    }
    cout <<"在第"<<bestman.generate<<"代时得到的最大值;"<<bestman;
    finish = clock();
    printf("程序共耗时为%3lf秒\n", ((double)finish -(double)start) / CLOCKS_PER_SEC);
    fout.close();
    return 0;  
}
