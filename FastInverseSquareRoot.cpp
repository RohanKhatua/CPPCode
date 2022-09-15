#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
using namespace std;

float Q_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    i = *(long *)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));
    return y;
}

float general_sqrt(float number){
    return pow(number,-0.5);
}

int main(){
    clock_t fast_time,general_time;
    



    general_time=clock();
    for (int i=0;i<INT_MAX;i++){
        float x = rand();
        float ans=general_sqrt(x);
        //376.789 seconds on average
    }
    general_time=clock()-general_time;

    fast_time=clock();
    for (int i=0;i<INT_MAX;i++){
        float x = rand();
        float ans=Q_rsqrt(x);
//      48.062 seconds on average
//      87% reduction

    }
    fast_time=clock()-fast_time;

    float time1 = (float)fast_time/CLOCKS_PER_SEC;
    float time2 = (float)general_time/CLOCKS_PER_SEC;

    cout<<"Fast Inverse Square Root Time : "<<time1<<endl;
    cout<<"General Inverse Square Root Time : "<<time2<<endl;
}