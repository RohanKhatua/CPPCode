#include <bits/stdc++.h>
using namespace std;

float getPythagoreanDistance(int x1, int y1, int x2, int y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

vector<pair<int,int>> getEight(int x, int y, int m){
    vector<pair<int,int>> eight;

    

    eight.push_back(make_pair(x+2,y+1));
    eight.push_back(make_pair(x+2,y-1));
    eight.push_back(make_pair(x-2,y+1));
    eight.push_back(make_pair(x-2,y-1));
    eight.push_back(make_pair(x+1,y+2));
    eight.push_back(make_pair(x+1,y-2));
    eight.push_back(make_pair(x-1,y+2));
    eight.push_back(make_pair(x-1,y-2));
    
    for (pair<int,int> square : eight){
        if (square.first<0 || square.second<0 || square.first>=m || square.second>=m){
            eight.erase(remove(eight.begin(),eight.end(),square),eight.end());
        }
    }

}

bool getCloser(int x1, int y1, int x2, int y2, int n, int m){
    if (x1==x2 && y1==y2){
        return true;
    }
    else if (n==0){
        return false;
    }
    else{
        vector<pair<int,int>> eight = getEight(x1,y1,m);
        vector<float> pythagoreanDistances;

        for (pair<int,int> square : eight){
            pythagoreanDistances.push_back(getPythagoreanDistance(square.first,square.second,x2,y2));
        }

        int minIndex = min_element(pythagoreanDistances.begin(),pythagoreanDistances.end()) - pythagoreanDistances.begin();
        pair<int,int> bestSquare = eight[minIndex];

        return getCloser(bestSquare.first,bestSquare.second,x2,y2,n-1, m);
    }
}



int main(){

    int x1,y1,x2,y2;
    int n;
    int m;
    cin>>x1>>y1>>x2>>y2>>n>>m;

    int arr[m][m];

    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            arr[i][j]=0;
        }
    }

    bool res = getCloser(x1,y1,x2,y2,n,m);

    cout<<res?"TRUE":"FALSE";
    
}