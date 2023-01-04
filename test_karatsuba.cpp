#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "fast_mult.cpp"

int main(){
    clock_t fast_time,general_time;

    general_time=clock();

    for (int i=0;i<10000;i++){
        int rand1 = rand() % 10000000 + 10000000;
        int rand2 = rand() % 10000000 + 10000000;
        int x = rand1*rand2;
    }

    general_time = clock()-general_time;

    fast_time=clock();

    for (int i=0;i<10000;i++){
        int rand1 = rand() % 10000000 + 10000000;
        int rand2 = rand() % 10000000 + 10000000;
        int x = rand1*rand2;
    }

    fast_time=clock()-fast_time;

    float time1 = (float)fast_time/CLOCKS_PER_SEC;
    float time2 = (float)general_time/CLOCKS_PER_SEC;

    cout<<"Karatsuba Time = "<<time1<<endl;
    cout<<"Normal Time = "<<time2<<endl;
}