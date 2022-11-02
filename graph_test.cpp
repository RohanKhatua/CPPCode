#include<bits/stdc++.h>
#include "graph_utility.cpp"
using namespace std;

int main(){
    Graph g;
    g.num_nodes = 5;
    g.node_names = {'A','B','C','D','E'};
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,3);
    g.add_edge(2,4);
    g.add_edge(3,4);
    g.print_adjacency_matrix();
}