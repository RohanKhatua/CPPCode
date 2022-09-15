#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int linear_search(const int* a, int n, int x){
    for (int i=0;i<n; i++){
        if (a[i]==x) return i;

    }
    return -1;
}

vi vecMinus(vi a, vi b){
    vi c;
    
    for (int & i : a) {
        if (find(b.begin(),b.end(),i)==b.end()){
            c.push_back(i);
        }
    }

    return c;
}

bool vecEquals(vi a, vi b){
    for (int & i : a){
        if (find(b.begin(),b.end(),i)==b.end()) return false;
    }
    return true;
}

int main(){
    const int n = 5;
    int l[n]={99};
    int adj[n][n]={{99,10,99,5,99},{99,99,1,2,99},{99,99,99,99,4},{99,3,9,99,2},{7,99,6,99,99}};

    vi all_nodes;

    all_nodes.reserve(n);

    for (int i=0; i<n; i++){
        all_nodes.push_back(i);
    }
    vi traversed_nodes;

    int source=0;

    traversed_nodes.push_back(source);

    vi non_traversed_nodes = vecMinus(all_nodes,traversed_nodes);



    for (int current_node : non_traversed_nodes){
        l[current_node]=adj[source][current_node];

    }



    while (!vecEquals(all_nodes,traversed_nodes)){

        vi distances_to_non_traversed_nodes;

        distances_to_non_traversed_nodes.reserve(non_traversed_nodes.size());

        for (int & non_traversed_node : non_traversed_nodes){
            distances_to_non_traversed_nodes.push_back(l[non_traversed_node]);
        }

        int min_distance = *min_element(distances_to_non_traversed_nodes.begin(),distances_to_non_traversed_nodes.end());

        //look for min_distance in l and return the index, that is the value of closest_node


        
        int closest_node = linear_search(l,n,min_distance);

        traversed_nodes.push_back(closest_node);

        non_traversed_nodes = vecMinus(all_nodes,traversed_nodes);

        for (int current_node : non_traversed_nodes){
            l[current_node]=min(l[current_node],l[closest_node]+adj[closest_node][current_node]);
//            closest_node=current_node;
        }
    }

    for (int i =0;i<n;i++){
        if (i!=source) {
            cout << "Distance to node "<<i<<" is "<<l[i] << endl;
        }
    }



}