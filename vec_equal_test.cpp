#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

bool vecEquals(vi a, vi b){
    for (auto i =a.begin();i!=a.end();i++){
        if (find(b.begin(),b.end(),*i)==b.end()) return false;
    }
    return true;
}

int main(){
    vi a = {1,2,3};
    vi b = {1,2,3};

    if (vecEquals(a,b)) cout<<"Equal";
    else cout<<"Not equal";
}
