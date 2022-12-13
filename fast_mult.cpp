#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int numDigits(int x){
    return 1+floor(log10(float(x)));
}

vi getVectorofDigits(int x){
    vi v;
    while (x>0){
        int d = x%10;
        v.insert(v.begin(),d);
        x/=10;
    }
    return v;
}

int getNumberfromVector(vi x){
    int n=0;
    int power = x.size()-1;
    for (int dig:x){
        n+=pow(10,power)*dig;
        power--;
    }

    return n;
}

vi vec_slice(vi x, int start, int end){
    auto ptr1 = x.begin()+start;
    auto ptr2 = x.begin()+end+1;

    vi res;

    for (auto ptr = ptr1;ptr!=ptr2;ptr=ptr+1){
        res.push_back(*ptr);
    }

    return res;
}

int karatsuba(int a, int b){
    if (a<10 && b<10){
        return a*b;
    }

    int len1 = numDigits(a);
    int len2 = numDigits(b);

    int max_len = max(len1, len2);
    int target_len = max_len%2==0?max_len:max_len+1;

    vi v1=getVectorofDigits(a);
    vi v2=getVectorofDigits(b);

    int diff1=target_len-v1.size();
    int diff2=target_len-v2.size();

    for (int i=0;i<diff1;i++){
        v1.insert(v1.begin(),0);
    }

    for (int i=0;i<diff2;i++){
        v2.insert(v2.begin(),0);
    }

    //slice v1, v2 into a1,a2 and b1,b2, then convert them back into int and recursively calculate result

    vi a1_v = vec_slice(v1,0,v1.size()/2-1);
    vi a2_v = vec_slice(v1, (v1.size()/2), v1.size()-1);

    vi b1_v = vec_slice(v2,0,v2.size()/2-1);
    vi b2_v = vec_slice(v2, (v2.size()/2), v2.size()-1);

    int A = karatsuba(getNumberfromVector(a1_v), getNumberfromVector(b1_v));
    int B = karatsuba(getNumberfromVector(a2_v), getNumberfromVector(b2_v));
    int sum1 = getNumberfromVector(a1_v)+getNumberfromVector(a2_v);
    int sum2 = getNumberfromVector(b1_v)+getNumberfromVector(b2_v);
    int C = karatsuba(sum1, sum2);
    int D = C - A - B;

    return (pow(10, target_len)*A+pow(10, target_len/2)*D+B);
}

int main(){
    int x,y;

    cin>>x>>y;
    cout<<karatsuba(x,y);

    return 0;
}