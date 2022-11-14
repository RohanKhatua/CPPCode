#include <iostream>
using namespace std;

void hanoi(int,char,char,char);    

int main(){
    int n;
    char from,to,via;
    cout<<"Enter number of discs : ";
    cin>>n;
    cout<<"Enter the initial, intermediate, and final discs : ";
    cin>>from>>via>>to;
    hanoi(n,from,to,via);
    
}

void move(char from, char to){
    cout<<"Move disc from "<<from<<" to "<<to<<endl;
}

void hanoi(int n, char from, char via, char to){
    if (n==0) return;
    else {
        hanoi(n-1,from,to,via);
        move(from,to);
        hanoi(n-1,via,from,to);
    }
}
