#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n, m;          // number of vertices and edges
int s, t;          // source and sink vertices
int c[MAXN][MAXN]; // capacity matrix
int f[MAXN][MAXN]; // flow matrix

int bfs(int s, int t, int parent[])
{
    // create a parent array to store the path from s to t
    memset(parent, -1, sizeof(parent));

    queue<int> q;
    q.push(s);
    parent[s] = -2;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (parent[v] == -1 && f[u][v] < c[u][v])
            {
                parent[v] = u;
                q.push(v);
            }
        }
    }

    // if we reached the sink, return the augmented path capacity
    if (parent[t] != -1)
    {
        int u = parent[t];
        int path_flow = INT_MAX;
        while (u != -2)
        {
            path_flow = min(path_flow, c[u][t] - f[u][t]);
            t = u;
            u = parent[u];
        }
        return path_flow;
    }
    return 0;
}

int maxflow(int s, int t)
{
    int parent[MAXN];
    int flow = 0;

    // find augmenting paths and update the flow matrix
    while (int path_flow = bfs(s, t, parent))
    {
        flow += path_flow;
        int u = t;
        while (u != s)
        {
            int v = parent[u];
            f[v][u] += path_flow;
            f[u][v] -= path_flow;
            u = v;
        }
    }

    return flow;
}

int main()
{
    // read input
    cout<<"Enter number of vertices, edges, source and sink vertex :";
    cin >> n >> m >> s >> t;
    cout<<"Enter edges with their capacities :";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
    }

    int max_flow = maxflow(s, t);

    // compute the value of the cut (S,T)
    bool vis[MAXN];
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (c[u][v] - f[u][v] > 0 && !vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    int cut_value = 0;
    for (int u = 0; u < n; u++)
    {
        if (vis[u])
        {
            for (int v = 0; v < n; v++)
            {
                if (!vis[v] && c[u][v] > 0)
                {
                    cut_value += c[u][v];
                }
            }
        }
    }

    // print the result
    cout << "Maximum flow: " << max_flow << endl;
    cout << "Value of the cut: " << cut_value << endl;

    // check if |f| = f(S,T)
    cout << "Absolute value of the flow: " << abs(max_flow) << endl;
    cout << "Value of the cut: " << cut_value << endl;
    if (abs(max_flow) == cut_value)
    {
        cout << "The equality |f| = f(S,T) holds." << endl;
    }
    else
    {
        cout << "The equality |f| = f(S,T) does not hold." << endl;
    }

    return 0;
}
