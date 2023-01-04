#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi getAdjacentVertices(int vertex, vector<vector<int>> adj){
    vi adjacentVertices;
    for (int i=0;i<adj.size();i++){
        if (adj[vertex][i]==1){
            adjacentVertices.push_back(i);
        }
    }
    return adjacentVertices;
}

int colorGraph(const vector<vector<int>>& adj, int vertices){
    vi colors(vertices);
    for (int i=0;i<vertices;i++){
        colors[i]=i;
    }
    vector<vi> color_combinations;
    for (int i=0;i<vertices;i++){
        vi temp;
        for (int j=0;j<=i;j++){
            temp.push_back(j);
        }
        color_combinations.push_back(temp);
    }
    vi chosenColor (vertices);
    for (int i=0;i<vertices;i++){
        chosenColor[i]=-1;
    }
    for (int i=0;i<vertices;i++){
        chosenColor[i]=color_combinations[i][0];
        vi adjacentVertices = getAdjacentVertices(i, adj);
        for (int adjacentVertex : adjacentVertices){
            auto colorRemovePos = find(color_combinations[adjacentVertex].begin(), color_combinations[adjacentVertex].end(), chosenColor[i]);
            if (colorRemovePos!=color_combinations[adjacentVertex].end())
                color_combinations[adjacentVertex].erase(colorRemovePos);
        }
    }

    return *max_element(chosenColor.begin(), chosenColor.end()) +1;


}

int main(){

    int m;
    cin >> m;

    vector<vector<int>> adj(m);

    for (int i=0;i<m;i++){
        cout<<"Enter elements of row "<<i+1<<" : "<<endl;
        vi temp;
        for (int j=0;j<m;j++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        adj[i]=temp;
        cout<<endl;
    }



    int n = colorGraph(adj, m);

    cout <<"Chromatic number is "<<n<<endl;


    return 0;
}