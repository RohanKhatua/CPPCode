#include <iostream>
using namespace std;
void merge(int *arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = low;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    int a[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int n = sizeof(a) / sizeof(int);
    mergeSort(a, 0, n - 1);
    cout << "The elements in sorted order are : "
         << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
}