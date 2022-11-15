// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// adjacency matrix
vector<vector<int>> adj;

vector<char> node_names;

// function to perform DFS on the graph
void dfs(int start)
{

    vector<bool> visited = vector<bool>(adj.size(),false);

	// Print the current node
	cout << node_names[start] << " ";

	// Set current node as visited
	visited[start] = true;

	// For every node of the graph
	for (int i = 0; i < adj[start].size(); i++) {

		// If some node is adjacent to the current node
		// and it has not already been visited
		if (adj[start][i] == 1 && (!visited[i])) {
			dfs(i);
		}
	}
}

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
       

    // perform dfs on the graph
    dfs(0);
}
