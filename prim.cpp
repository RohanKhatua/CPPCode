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
    // returns the index where the closest node is if the node is contained in non_travsersed nodes
    // the second check is done so we don't get an older node back
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x && vecContains(non_traversed_nodes, i))
        {
            return i;
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
    // bigger vector first
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

    map<int, int> last_updated;
    for (int &node : all_nodes)
    {
        last_updated[node] = node;
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
            l[current_node] = adj[source][current_node]; // initialising output vector l
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
            // finding the closest node

            int closest_node = linear_search(l, n, min_distance, non_traversed_nodes);

            // avoiding duplicate nodes being added to traversed
            if (!vecContains(traversed_nodes, closest_node))
            {
                traversed_nodes.push_back(closest_node);
            }

            // update non traversed
            non_traversed_nodes = vecMinus(all_nodes, traversed_nodes);

            // update l for all non_traversed
            for (int current_node : non_traversed_nodes)
            {
                int copy = l[current_node];
                l[current_node] = min(l[current_node], adj[closest_node][current_node]);
                if (l[current_node] != copy)
                {
                    last_updated[current_node] = closest_node;
                }
            }
        }

        cout << "Chosen edges : " << endl;
        cout << "From " << source_name << ":" << endl;

        for (int &traversed_node : traversed_nodes)
        {
            if (traversed_node != source)
            {
                int dest_node;
                // cout << "Edge from " << node_names[traversed_node] << " to " << node_names[last_updated[traversed_node]] << " with weight " << adj[traversed_node][last_updated[traversed_node]] << endl;
                // cout<<"Value of out vec of "<<traversed_node<<" "<<l[traversed_node]<<endl;
                for (int i=0;i<n;i++){
                    if (adj[i][traversed_node]==l[traversed_node]){
                        dest_node=i;
                        break;
                    }
                }

                cout<<"Edge from "<<node_names[traversed_node]<<" to "<<node_names[dest_node]<<endl;
            }
        }
    }
}