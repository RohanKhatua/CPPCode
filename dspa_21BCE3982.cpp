#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define im 5000 // defining a large number
#define endl "\n"

bool vecContains(vi a, int x)
{
    return (find(a.begin(), a.end(), x) != a.end());
}

int linear_search(const int *a, int n, int x, vi non_traversed_nodes)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            if (vecContains(non_traversed_nodes, i))
            {
                return i;
            }
        }
    }
    return -1;
}

vi vecMinus(vi a, vi b)
{
    vi c;

    for (int &i : a)
    {
        if (!vecContains(b, i))
        {
            c.push_back(i);
        }
    }

    return c;
}

bool oneSidedVecEqual(vi a, vi b)
{
    for (int &i : a)
    {
        if (!vecContains(b, i))
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;
    int l[n] = {im};
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
                adj[i][j] = im;
            else
            {
                adj[i][j] = x;
            }
        }
    }

    cout << "Enter the nodes in order" << endl;

    char node_names[n];

    for (char &node_name : node_names)
    {
        cin >> node_name;
    }

    vi all_nodes;

    all_nodes.reserve(n);

    for (int i = 0; i < n; i++)
    {
        all_nodes.push_back(i);
    }

    for (char source_name : node_names)
    {
        vi traversed_nodes;

        auto it = find(node_names, node_names + n, source_name);
        int source = distance(node_names, it);

        traversed_nodes.push_back(source);

        vi non_traversed_nodes = vecMinus(all_nodes, traversed_nodes);

        for (int current_node : non_traversed_nodes)
        {

            l[current_node] = adj[source][current_node];
        }

        while (!oneSidedVecEqual(all_nodes, traversed_nodes))
        {

            vi distances_to_non_traversed_nodes;

            distances_to_non_traversed_nodes.reserve(non_traversed_nodes.size());

            for (int &non_traversed_node : non_traversed_nodes)
            {
                distances_to_non_traversed_nodes.push_back(l[non_traversed_node]);
            }

            int min_distance = *min_element(distances_to_non_traversed_nodes.begin(),
                                            distances_to_non_traversed_nodes.end());

            int closest_node = linear_search(l, n, min_distance, non_traversed_nodes);

            if (!vecContains(traversed_nodes, closest_node))
            {
                traversed_nodes.push_back(closest_node);
            }

            non_traversed_nodes = vecMinus(all_nodes, traversed_nodes);

            for (int current_node : non_traversed_nodes)
            {
                l[current_node] = min(l[current_node], l[closest_node] + adj[closest_node][current_node]);
            }
        }

        cout << "From " << source_name << ":" << endl;

        for (int i = 0; i < n; i++)
        {
            if (i != source)
            {
                cout << "Distance to node " << node_names[i] << " is " << l[i] << endl;
            }
        }
    }
}