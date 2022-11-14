#include <iostream>
using namespace std;
int main()
{
    int a[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int n = sizeof(a) / sizeof(int);
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = a[i];
        while (j > -1 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
    cout << "The elements in sorted order are : "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}