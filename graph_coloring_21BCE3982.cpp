#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Graph{
public:
    int n;
    vector<pair<int,int>> edges;

    Graph(int n, vector<pair<int,int>> edges){
        this->n=n;
        this->edges=edges;
    }

    //Function to return the adjacaency matrix of the graph from the edges

    vector<vi> getAdjacencyMatrix(){
        vector<vi> adj;
        for (int i=0;i<n;i++){
            vi temp;
            for (int j=0;j<n;j++){
                temp.push_back(0);
            }
            adj.push_back(temp);
        }
        for (auto edge : edges){
            adj[edge.first][edge.second]=1;
            adj[edge.second][edge.first]=1;
        }
        return adj;    
    }
};

//Utility function to get the adjacent vertices of a vertex

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
            temp.push_back(j); //generating possible colors for each vertex
        }
        color_combinations.push_back(temp);
    }
    vi chosenColor (vertices);
    for (int i=0;i<vertices;i++){
        chosenColor[i]=-1; //initializing the chosen color of each vertex to -1
    }
    for (int i=0;i<vertices;i++){
        chosenColor[i]=color_combinations[i][0];
        vi adjacentVertices = getAdjacentVertices(i, adj);
        for (int adjacentVertex : adjacentVertices){
            //finding iterator to the chosen color
            auto colorRemovePos = find(color_combinations[adjacentVertex].begin(), color_combinations[adjacentVertex].end(), chosenColor[i]);
            if (colorRemovePos!=color_combinations[adjacentVertex].end())
                color_combinations[adjacentVertex].erase(colorRemovePos);
        }
    }

    for (int i=0;i<chosenColor.size();i++){
        cout<<"Chosen colour of Vertex "<<i<<" is "<<chosenColor[i]<<endl;
    }

    return *max_element(chosenColor.begin(), chosenColor.end()) +1;


}

int main(){

    int m = 14;
   
    vector<pair<int,int>> edges;

    //Edges for the graph

    edges = {        
        {0,1}, {0,5}, {0,9}, 
        {1,5}, {1,6}, {1,2}, 
        {2,6}, {2,7}, {2,3},
        {3,7}, {3,4}, {3,8}, {3,12},
        {4,8}, {4,13},
        {5,6}, {5,9},
        {6,7}, {6,10}, {6,11}, {6,9},
        {7,11}, {7,12},
        {8,12}, {8,13},
        {9,10},
        {10,11},
        {11,12},
        {12,13}
    };

    vector<vector<int>> adj = Graph(m, edges).getAdjacencyMatrix();

    int n = colorGraph(adj, m);

    cout <<"Chromatic number is "<<n<<endl;

    return 0;
}