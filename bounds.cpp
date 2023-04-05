#include <bits/stdc++.h>
using namespace std;

int p[] = {6, 10, 18, 15, 3, 5, 7};
int w[] = {1, 2, 4, 5, 1, 3, 7};
int n = 7;

int upperBound(int cp, int cw, int k, int m)
{
    int b = cp;
    int c = cw;

    for (int i = k; i < n; i++)
    {
        if (c + w[i] <= m)
        {
            c += w[i];
            b -= p[i];
        }
        else
            break;
    }
    return b;
}

float lowerBound(int cp, int cw, int k, int m)
{
    float b = cp;
    int c = cw;

    for (int i = k; i < n; i++)
    {
        c = c + w[i];
        if (c <= m)
        {
            b -= p[i];
        }
        else
        {
            b -= (1 - (c - m) / (float)w[i]) * p[i];
            break;
        }
    }

    return b;
}

int main()
{

    int choice;
    cout << "Enter 1 for upper bound and 2 for lower bound: ";
    cin >> choice;
   
        if (choice == 1)
        {
            cout << "Upper Bound :";
            int cp, cw, k, m;
            cin >> cp >> cw >> k >> m;
            cout << "Upper Bound : " << upperBound(cp, cw, k, m) << endl;
        }

        if (choice == 2)
        {
            cout << "Lower Bound :";
            int cp, cw, k, m;
            cin >> cp >> cw >> k >> m;
            cout << "Lower Bound : " << lowerBound(cp, cw, k, m) << endl;
        }

        
    
}