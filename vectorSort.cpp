#include <bits/stdc++.h>
using namespace std;



int main(){

    vector<int> numbers = {0,2,-1,10,5};

    sort(numbers.begin(),numbers.end()-2,greater<int>());

    for (int num:numbers){
        cout<<num<<"\t";
    }

    return 0;
}