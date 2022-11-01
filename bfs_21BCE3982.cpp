#include <bits/stdc++.h>
using namespace std;

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
    char source_node;
    cin>>source_node;

    int source_node_index = find(node_names,node_names+n,source_node)-node_names;
    //getting the index of the source node

    int visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0; 
        //setting all nodes to not visited
        //0 is not visited
        //1 is visited
    }
    queue<int> q;
    q.push(source_node_index); //setting source node
    visited[source_node_index]=1; //source node is visited at the beginning of bfs

    cout<<"BFS Traversal : ";
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<node_names[x]<<" ";
        for(int i=0;i<n;i++){
            //if the edge exists and the node has not been previously visited, visit it
            if(adj[x][i]==1 && visited[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return 0;
}