#include <stdio.h>

int binary_search(int left, int right, int *arr, int x)
{

    if (left <= right)
    {
        int mid = left + (right - left) / 2; // left + right could overflow integer bounds
        if (arr[mid] == x)
        {
            return mid;
        }

        else if (arr[mid] < x)
        {
            binary_search(mid + 1, right, arr, x);
        }

        else if (arr[mid] > x)
        {
            binary_search(left, mid - 1, arr, x);
        }
    }
    else
        return -1;

}

int main()
{

    printf("Enter number of elements : ");
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int x;

    printf("Enter search element : ");
    scanf("%d", &x);

    int index = binary_search(0, n - 1, arr, x);
    if (index != -1)
        printf("Index = %d", index);
    else
        printf("Search element not found");
}