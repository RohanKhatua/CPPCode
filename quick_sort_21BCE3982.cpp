#include <iostream>
using namespace std;
int n;
void printArray(int *a)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << "\n";
}
int partition(int *a, int low, int high)
{
    int pivot = a[high];

    printArray(a);
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    int temp = a[i];
    a[i] = pivot;
    a[high] = temp;
    return i;
}
void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int p_index = partition(a, low, high);
        quickSort(a, low, p_index - 1);
        quickSort(a, p_index + 1, high);
    }
}
int main()
{
    int a[] = {3, 41, 52, 26, 38, 57, 9, 49};
    n = sizeof(a) / sizeof(int);
    quickSort(a, 0, n - 1);
    cout << "The sorted array elements are : "<<"\n";
    printArray(a);
}