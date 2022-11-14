#include <bits/stdc++.h>
using namespace std;
int linearSearch(int *a, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}
int n;
int binarySearch(int *a, int low, int high, int x)
{
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
    if (low < high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == x)
            return mid;
        if (a[mid] < x)
            return binarySearch(a, mid + 1, high, x);
        else
            return binarySearch(a, low, mid - 1, x);
    }
    return -1;
}
int main()
{
    int a[] = {5, 13, 2, 25, 7, 17, 20, 8, 4, 45, 48, 12, 13, 10, 22, 11, 44, 99, 203, 17, 79, 46, 147, 58, 14};
    n = sizeof(a) / sizeof(int);
    int x;
    cout << "Enter Search element : ";
    cin >> x;
    int lin_index = linearSearch(a, x, n);
    int bin_index = binarySearch(a, 0, n - 1, x);
    if (lin_index != -1)
        cout << "Element found through linear search at " << lin_index << "\n";
    if (bin_index != -1)
        cout << "Element found through binary search at " << bin_index << "\n";
    else if (lin_index == -1 || bin_index == -1)
        cout << "Element not found";
}