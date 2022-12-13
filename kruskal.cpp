#include <bits/stdc++.h>

using namespace std;
#define bn 5000
#define vi vector<int>

class Edge {
public:
    pair<int, int> vertices;
    int weight{};
};

bool compareWeights(const Edge &left, const Edge &right) {
    return left.weight <= right.weight;
}

void printEdge(Edge edge, char *node_names) {
    cout << "Edge between " << node_names[edge.vertices.first] << " and " << node_names[edge.vertices.second]
         << " with weight = " << edge.weight << endl;
}

int find_representative_node(vi node_set) {
    if (!node_set.empty()) {
        int min_el = *min_element(node_set.begin(), node_set.end());
        return min_el;
    }
    return 0;
}

int main() {
    int n = 5;
//    cout << "Enter the number of nodes : ";
//    cin >> n;
    int adj[5][5] = {{bn, 2, bn, bn, 3},
                     {2, bn, 4,  5,  6},
                     {bn, 4, bn, 2, bn},
                     {bn, 5, 2,  bn, 1},
                     {3,  6, bn, 1, bn}};
//    cout << "Enter the elements of the adjacency matrix : " << endl;
//    for (int i = 0; i < n; i++)
//    {
//        cout << "Enter elements of row " << i << endl;
//        for (int j = 0; j < n; j++)
//        {
//            int x;
//            cin >> x;
//            if (x == 0)
//            {
//                adj[i][j] = bn;
//            }
//            else
//                adj[i][j] = x;
//        }
//    }
//    cout << "Enter the nodes in order" << endl;

    char node_names[5] = {'A', 'B', 'C', 'D', 'E'};
//    for (char &node_name : node_names)
//    {
//        cin >> node_name;
//    }



    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = adj[i][j];
            if (weight != bn) {
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
    set<int> mst_vertices;
    vector<vector<int>> node_sets;


    for (int i = 0; i < n; i++) {
        vi temp_set;
        temp_set.push_back(i);
        node_sets.push_back(temp_set);
    }
    for (Edge current_edge: edges) {
        if (node_sets.size() != 1) {
            int smaller_vertex = min(current_edge.vertices.first, current_edge.vertices.second);
            int greater_vertex = max(current_edge.vertices.first, current_edge.vertices.second);

            vi greater_set;
            vi smaller_set;

            vector<vector<int>>::iterator greater_it;
            vector<vector<int>>::iterator smaller_it;

            for (int i = 0; i < node_sets.size(); i++) {
                vi node_set = node_sets[i];
                greater_it = node_sets.begin();
                if (find(node_set.begin(), node_set.end(), greater_vertex) != node_set.end()) {
                    greater_set = node_set;
                    greater_it = greater_it + i;
                    break;
                }
            }


            for (int i = 0; i < node_sets.size(); i++) {
                vi node_set = node_sets[i];
                smaller_it = node_sets.begin();
                if (find(node_set.begin(), node_set.end(), smaller_vertex) != node_set.end()) {
                    smaller_set = node_set;
                    smaller_it = smaller_it + i;
                    break;
                }
            }

            if (find_representative_node(smaller_set) !=
                find_representative_node(greater_set)) {
                mst_edges.push_back(current_edge);

                for (int &ele: greater_set) {
                    smaller_set.push_back(ele);
                }
                *smaller_it = smaller_set;

                node_sets.erase(greater_it);
            }
        } else {
            break;
        }
    }
    cout << "Number of chosen edges = " << mst_edges.size() << endl;
    cout << "Chosen edges : " << endl;
    int mst_sum = 0;
    for (Edge &edge: mst_edges) {
        printEdge(edge, node_names);
        mst_sum += edge.weight;
    }
    cout << "Cost of MST = " << mst_sum;
}