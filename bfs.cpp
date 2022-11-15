#include <bits/stdc++.h>
using namespace std;

#define bn 5000

vector<vector<int>> adj;
vector<char> node_names;

void bfs(int start)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    vector<bool> visited(adj.size(), false);
    vector<int> q;
    q.push_back(start);

    // Set source as visited
    visited[start] = true;

    int vis;
    while (!q.empty())
    {
        vis = q[0];

        // Print the current node
        cout << node_names[vis] << " ";
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < adj[vis].size(); i++)
        {
            if (adj[vis][i] == 1 && (!visited[i]))
            {

                // Push the adjacent node to the queue
                q.push_back(i);

                // Set
                visited[i] = true;
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
