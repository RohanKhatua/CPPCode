#include <bits/stdc++.h>
using namespace std;


//function to calculate number of digits in a number
int numDigits(int x){
    return 1+floor(log10(float(x)));
}

//function to perform karatsuba multiplication
long long karatsuba(long x, long y){

    //if both numbers are single digit, return their product directly
    if (x<10 && y<10){
        return x*y;
    }

    int n = max(numDigits(x), numDigits(y));
    int m = n/2;

    //Split both numbers into two parts
    long a1 = x/pow(10,m);
    long a2 = x%int(pow(10,m));
    long b1 = y/pow(10,m);
    long b2 = y%int(pow(10,m));

    //Calculating Karatsuba coefficients
    long A = karatsuba(a1,b1);
    long B = karatsuba(a2,b2);
    long C = karatsuba(a1+a2,b1+b2);
    long D = C-A-B;

    //returning the final answer
    long long ans = A*(long)pow(10,2*m)+D*(long)pow(10,m)+B;
    return ans;
}



int main(){
    long x,y;
    cout<<"Enter two numbers : ";
    cin>>x>>y;
    cout<<"Product of "<<x<<" and "<<y<<" is "<<karatsuba(x,y)<<endl;

    return 0;
}
