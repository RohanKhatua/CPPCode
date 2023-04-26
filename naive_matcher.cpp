#include <bits/stdc++.h>
using namespace std;

int main()
{

    cout << "Enter String and Pattern : ";
    string s, p;
    cin >> s >> p;
    bool found = false;
    for (int i = 0; i <= s.length() - p.length(); i++)
    {
        string sub = s.substr(i,p.length());
        cout<<"Comparing "<<sub<<" with pattern "<<p<<endl;
        if (sub == p)
        {
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Pattern not found";

    return 0;
}