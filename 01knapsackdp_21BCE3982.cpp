// 0-1 knapsack using dynamic programming
#include <iostream>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main()
{
    cout << "Enter the number of items : ";
    int n;
    cin >> n;
    int val[n];
    int wt[n];
    cout<<"Enter capacity of knapsack : ";
    int capacity;
    cin>>capacity;
    cout<<"Enter the profits of the items :"<<endl;
    for (int i=0;i<n;i++){
        cin>>val[i];
    }
    cout<<"Enter the weights of the items :"<<endl; 
    for (int i=0;i<n;i++){
        cin>>wt[i];
    }
    cout << "The total profit is : "<<knapSack(capacity, wt, val, n);
    return 0;
}
