#include <bits/stdc++.h>
using namespace std;

const int N=1005;
int n,W,w[N],v[N],f[N];

bool cmp(int a,int b){
    return (double)v[a]/w[a]>(double)v[b]/w[b];
}

int bound(int u,int k){
    int tot=0;
    int j=k+1;
    while (j<=n&&tot+w[f[j]]<=W){
        tot+=w[f[j]];
        u+=v[f[j]];
        j++;
    }
    if (j<=n) u+=v[f[j]]*(W-tot)/w[f[j]];
    return u;
}

void knapsack(int u,int k){
    if (k==n){
        cout<<u<<endl;
        exit(0);
    }
    if (bound(u,k)<=u) return;
    knapsack(u+v[f[k+1]],k+1);
    knapsack(u,k+1);
}

int main(){
    cin>>n>>W;
    for (int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
        f[i]=i;
    }
    sort(f+1,f+n+1,cmp);
    knapsack(0,0);
    return 0;
}
