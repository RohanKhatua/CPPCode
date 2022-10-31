#include <bits/stdc++.h>
using namespace std;
#define bn 5000
#define vi vector<int>
class Edge
{
public:
    pair<int, int> vertices;
    int weight;
};
bool compareWeights(const Edge &left, const Edge &right)
{
    return left.weight <= right.weight;
}
bool printEdge(Edge edge, char *node_names)
{
    cout << "Edge between " << node_names[edge.vertices.first] << " and " << node_names[edge.vertices.second] << " with weight = " << edge.weight << endl;
}
int find_representative_node(vi node_set)
{
    if (node_set.size() != 0)
    {
        int min_el = *min_element(node_set.begin(), node_set.end());
        return min_el;
    }
}
int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;
    int adj[n][n];
    cout << "Enter the elements of the adjacency matrix : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements of row " << i << endl;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                adj[i][j] = bn;
            }
            else
                adj[i][j] = x;
        }
    }
    cout << "Enter the nodes in order" << endl;
    char node_names[n];
    for (char &node_name : node_names)
    {
        cin >> node_name;
    }
    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int weight = adj[i][j];
            if (weight != bn)
            {
                Edge current_edge;
                current_edge.vertices.first = i;
                current_edge.vertices.second = j;
                current_edge.weight = weight;
                edges.push_back(current_edge);
            }
        }
    }
    sort(edges.begin(), edges.end(), compareWeights);
    vector<Edge> mst_edges; // edges included in MST
    vector<vector<int>> node_sets;
    for (int i = 0; i < n; i++)
    {
        vi temp_set;
        temp_set.push_back(i);
        node_sets.push_back(temp_set);
    }
    for (Edge current_edge : edges)
    {
        int smaller_vertex = min(current_edge.vertices.first,
                                 current_edge.vertices.second);
        int greater_vertex = max(current_edge.vertices.first,
                                 current_edge.vertices.second);
        cout << "Edge between " << node_names[smaller_vertex] << " and "<<node_names[greater_vertex]<<endl;
            cout             << "Node sets of edges : " << endl;
        cout << "{";
        for (int &ele : node_sets[smaller_vertex])
        {
            cout << ele << " ";
        }
        cout << "}" << endl;
        cout << "{";
        for (int &ele : node_sets[greater_vertex])
        {
            cout << ele << " ";
        }
        cout << "}" << endl;
        if (find_representative_node(node_sets[smaller_vertex]) !=
            find_representative_node(node_sets[greater_vertex]))
        {
            mst_edges.push_back(current_edge);
            vi greater_set = node_sets[greater_vertex];
            for (int &ele : greater_set)
            {
                node_sets[smaller_vertex].push_back(ele);
            }
            node_sets.erase(node_sets.begin() + greater_vertex);
        }
    }
    cout << "Number of chosen edges = " << mst_edges.size() << endl;
    cout << "Chosen edges : " << endl;
    int mst_sum = 0;
    for (Edge &edge : mst_edges)
    {
        printEdge(edge, node_names);
        mst_sum += edge.weight;
    }
    cout << "Cost of MST = " << mst_sum;
}