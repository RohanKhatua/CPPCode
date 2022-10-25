#include <bits/stdc++.h>
using namespace std;

#define bn 5000
#define vi vector<int>

bool vecContains(vi a, int x){
    return (find(a.begin(),a.end(),x)!=a.end());
}

int linear_search(const int* a, int n, int x, vi non_traversed_nodes){
    for (int i=0;i<n;i++){
        if (a[i]==x){
            if (vecContains(non_traversed_nodes,i))
                return i;
        }
    }
    return -1;
}

vi vecMinus(vi a, vi b){
    vi c;

    for (int &i:a){
        if (!vecContains(b,i))  
            c.push_back(i);
    }
    return c;
}

bool oneSidedVecEqual (vi a, vi b){
    for (int &i:a){
        if (!vecContains(b,i))
            return false;
    }
    return true;
}

int main(){
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;
    int l[n] = {bn};
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
                adj[i][j] = bn;
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

    char source_name = node_names[0]; 
    //selecting the first node as the source

    vi traversed_nodes;


}
