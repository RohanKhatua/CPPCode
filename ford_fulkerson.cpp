#include<bits/stdc++.h>
using namespace std;

#define V 10

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V];

    int max_flow = 0;

    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{    
    
    int graph[V][V];

    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            graph[i][j] = 0;
        }
    }
    cout<<"Enter the adjacency matrix for the graph:"<<endl;
    for(int i=0; i<V; i++)
    {
        cout<<"Enter elements of row "<<(i+1)<<" : "<<endl;
        for(int j=0; j<V; j++)
        {
            int x;
            cin>>x;

            if (x==0){
                graph[i][j]=5000;
            }

            graph[i][j] = x;
            
        }
    }

    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            if (i==j){
                graph[i][j] = 0;
            }
        }
    }


    int s = 0, t = V-1;
    cout << "The maximum possible flow is " << fordFulkerson(graph, s, t) << endl;
    return 0;
}
