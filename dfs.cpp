#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int adj[][100], int n, int visited[], char node_names[]){
    visited[node]=1;
    cout<<node_names[node]<<" ";
    for(int i=0;i<n;i++){
        if(adj[node][i]==1 && visited[i]==0){
            dfs(i,adj,n,visited,node_names);
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    cout<<"Enter the adjacency matrix : "<<endl;
    int adj[n][n];
    for(int i=0;i<n;i++){
        cout<<"Enter elements of row "<<i<<":"<<endl;        
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }

    cout<<"Enter the nodes in order"<<endl;
    char node_names[n];
    for(char &node_name:node_names){
        cin>>node_name;
    }

    cout<<"Enter Source Node : ";

    

}