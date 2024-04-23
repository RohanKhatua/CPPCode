#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    for (int i = s.size()-1;i>=0;i--) {
        cout<<s[i];
    }
}