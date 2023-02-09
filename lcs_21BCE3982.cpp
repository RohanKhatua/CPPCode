#include <bits/stdc++.h> 
using namespace std;


vector<string> lcs(string x, string y, int m, int n, int k)
{ 
//    int L[m + 1][n + 1];

    vector<vector<int>> L (m+1);
    for (int i=0;i<m+1;i++){
        L[i].reserve(n+1);
    }
  
    for (int i = 0; i <= m; i++)
    { 
        for (int j = 0; j <= n; j++)
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; //Empty String
  
            else if (x[i - 1] == y[j - 1]) //Characters are same, increment the length
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
                //Character are not same, we compare the previous lengths and choose a maximum
        } 
    }

    vector<string> answers;

    for (int i=0;i<m+1;i++){
        for (int j=0;j<n+1;j++){
            if (L[i][j]<k && L[i][j]!=0){
                string ans;
                int i1=i;
                int j1=j;
                while (i1>0 && j1>0 && ans.length()<L[i][j]){
                    if (x[i1-1]==y[j1-1]){
                        ans=x[i1-1]+ans;
                        i1--;
                        j1--;
                    }
                    else if (L[i1-1][j1]>L[i1][j1-1])
                        i1--;
                    else j1--;
                }
                if (find(answers.begin(), answers.end(),ans)==answers.end())
                    answers.push_back(ans);
            }
        }
    }

    return answers;
} 

int main() 
{ 
    string x, y; 
    cout<<"Enter first String : ";
    cin>>x;
    cout<<"Enter second String : ";
    cin>>y;
    
    int m = x.length();
    int n = y.length();
    int k = min(m,n);

    cout<<"Common Subsequences of length less than "<<k<<" are : "<<endl;

    for (const string& ans: lcs(x,y,m,n,k)) {
        cout<<ans<<endl;
    }
  
    return 0; 
} 
