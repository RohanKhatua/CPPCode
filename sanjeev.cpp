#include <iostream>
using namespace std;
//0-1 knapsack using branch and bound
int max(int a, int b) {
    return (a > b) ? a : b;
}
int lowerBound(int i, int profit, int weight, int n, int W, int *p, int *w) {
    int j, k;
    int totweight;
    int result;
    if (weight >= W) {
        return 0;
    }
    else {
        result = profit;
        j = i + 1;
        totweight = weight;
        while ((j <= n) && (totweight + w[j] <= W)) {
            totweight = totweight + w[j];
            result = result + p[j];
            j++;
        }
        k = j;
        if (k <= n) {
            result = result + (W - totweight) * p[k] / w[k];
        }
        return result;
    }
}
int upperBound(int i, int profit, int weight, int n, int W, int *p, int *w) {
    int j, k;
    int totweight;
    int result;
    if (weight >= W) {
        return 0;
    }
    else {
        result = profit;
        j = i + 1;
        totweight = weight;
        while ((j <= n) && (totweight + w[j] <= W)) {
            totweight = totweight + w[j];
            result = result + p[j];
            j++;
        }
        return result;
    }
}
void knapsack(int i, int profit, int weight, int n, int W, int *p, int *w, int *x, int *maxprofit, int *bestx) {
    int u;
    if (weight <= W && profit > *maxprofit) {
        *maxprofit = profit;
        for (int j = 1; j <= n; j++) {
            bestx[j] = x[j];
        }
    }
    if (lowerBound(i, profit, weight, n, W, p, w) > *maxprofit) {
        u = upperBound(i, profit, weight, n, W, p, w);
        if (u > *maxprofit) {
            x[i + 1] = 1;
            knapsack(i + 1, profit + p[i + 1], weight + w[i + 1], n, W, p, w, x, maxprofit, bestx);
            x[i + 1] = 0;
            knapsack(i + 1, profit, weight, n, W, p, w, x, maxprofit, bestx);
        }
    }
}
int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int p[n + 1], w[n + 1], x[n + 1], bestx[n + 1];
    cout << "Enter the weights of the items: ";
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    cout << "Enter the profits of the items: ";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    int maxprofit = 0;
    knapsack(0, 0, 0, n, W, p, w, x, &maxprofit, bestx);
    cout << "The maximum profit is: " << maxprofit << endl;
    cout << "The items included in the knapsack are: ";
    for (int i = 1; i <= n; i++) {
        if (bestx[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}