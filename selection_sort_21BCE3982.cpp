#include <iostream>
using namespace std;
int main()
{
    int a[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
    cout << "The elemnts in sorted order are : "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}