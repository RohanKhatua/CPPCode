#include <bits/stdc++.h>
using namespace std;

#define bn 5000

vector<vector<int>> adj;
vector<char> node_names;

void bfs(int start)
{
    vector<bool>visited(adj.size(),false);
    visited[start]=true;

    vector<int>q;
    q.push_back(start);
    int vis;

    while (!q.empty()){
        vis=q[0];
        cout<<node_names[vis]<<" ";
        q.erase(q.begin());

        for (int i=0;i<adj.size();i++){
            if (adj[i][vis]==1 && !visited[i]){
                q.push_back(i);
                visited[i]=true;
            }
        }

    }
}

// Driver code
int main()
{
    int n;
    cout<<"Enter number of vertices : ";
    cin>>n;

    adj = vector<vector<int>>(n,vector<int>(n,0));
    //vector of n x n with all zeroes

    // adjacency matrix
    cout<<"Enter the adjacency matrix : "<<endl;
    for (int i=0;i<n;i++){
        cout<<"Enter elements of row "<<i<<" : "<<endl;
        for (int j=0;j<n;j++){
            cin>>adj[i][j];
        }        
    }

    node_names = vector<char>(n);

    cout<<"Enter the nodes in order : "<<endl;
    for (int i=0;i<n;i++){
        cin>>node_names[i];
    }
       

    // perform bfs on the graph
    bfs(0);
}
