#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

class Graph{
    public:
    int num_nodes;
    vector<char>node_names;     
    vector<Edge>edges;

    void add_edge(int u,int v){
        edges.push_back(Edge(u,v));
    }

    void add_edge_weighted(int u,int v,int w){
        edges.push_back(Edge(u,v,w));
    }

    void add_edge_directed(int u,int v){
        edges.push_back(Edge(u,v,true));
    }

    void add_edge_weighted_directed(int u,int v,int w){
        edges.push_back(Edge(u,v,w,true));
    }

    void add_edge_ch(char u, char v){
        int u_index = find(node_names.begin(),node_names.end(),u)-node_names.begin();
        int v_index = find(node_names.begin(),node_names.end(),v)-node_names.begin();
        add_edge(u_index,v_index);
    }


    void add_edge_ch_weighted(char u, char v, int w){
        int u_index = find(node_names.begin(),node_names.end(),u)-node_names.begin();
        int v_index = find(node_names.begin(),node_names.end(),v)-node_names.begin();
        add_edge_weighted(u_index,v_index, w);
    }

    void add_edge_ch_directed(char u, char v){
        int u_index = find(node_names.begin(),node_names.end(),u)-node_names.begin();
        int v_index = find(node_names.begin(),node_names.end(),v)-node_names.begin();
        add_edge_directed(u_index,v_index);
    }

    void add_edge_ch_weighted_directed(char u, char v, int w){
        int u_index = find(node_names.begin(),node_names.end(),u)-node_names.begin();
        int v_index = find(node_names.begin(),node_names.end(),v)-node_names.begin();
        add_edge_weighted_directed(u_index,v_index, w);
    }

    int** get_adjacency_matrix(){
        int **adj = new int*[num_nodes];
        for(int i=0;i<num_nodes;i++){
            adj[i] = new int[num_nodes];
        }
        for(int i=0;i<num_nodes;i++){
            for(int j=0;j<num_nodes;j++){
                adj[i][j] = 0;
            }
        }
        for(Edge edge:edges){
            adj[edge.src][edge.dest] = edge.weight;
            if (!edge.is_directed)  adj[edge.dest][edge.src] = edge.weight;
        }
        return adj;
    }    

    void print_adjacency_matrix(){
        int **adjacency_matrix = get_adjacency_matrix();
        for(int i=0;i<num_nodes;i++){
            for(int j=0;j<num_nodes;j++){
                cout<<adjacency_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void print_all_edges(){
        for (Edge edge:edges){
            edge.show_edge();
        }
    }
};

class Edge : Graph{
public:
    int src, dest, weight = 1;
    bool is_directed = false;

    Edge(int src, int dest){
        this->src = src;
        this->dest = dest;
    }

    Edge(int src, int dest, int weight){
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }

    Edge(int src, int dest, bool is_directed){
        this->src = src;
        this->dest = dest;
        this->is_directed = is_directed;
    }

    Edge(int src, int dest, int weight, bool is_directed){
        this->src = src;
        this->dest = dest;
        this->weight = weight;
        this->is_directed = is_directed;
    } 

    void show_edge(){
        if(is_directed){
            cout << node_names[src] << " -> " << node_names[dest];
        }
        else{
            cout << node_names[src] << " -- " << node_names[dest]; 
        }
        
        if (weight != 1)
            cout << " (weight: " << weight << ")"<<endl;
        else cout<<endl;    
    }
};