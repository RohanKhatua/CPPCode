#include <bits/stdc++.h>
using namespace std;


struct Item
{
    float weight;
    int value;
};


struct Node
{
    //level is the level of the node in the decision tree
    //profit is the profit of the nodes on the path from root to this node
    //bound is the upper bound of the maximum profit in the subtree of this node
    int level, profit, bound;
    float weight;
};


bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, int W, Item arr[])
{
    // if weight is greater than knapsack capacity, return 0 as expected bound
    if (u.weight >= W)
        return 0;

    // initialize bound on profit by current profit
    int profit_bound = u.profit;

    int j = u.level + 1;
    int totweight = u.weight;

    // checking index condition and knapsack capacity
    // condition
    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    // If k is not n, include last item fractionally for profit upper bound
    if (j < n)
        profit_bound += (W - totweight) * arr[j].value /
                        arr[j].weight;

    return profit_bound;
}

// Returns maximum profit we can get with capacity W
int knapsack(int W, Item arr[], int n)
{
    // sorting Item on basis of value per unit
    // weight in decreasing order using bubble sort

    for (int i=0;i<n-1;i++){
        for (int j = 0;j<n-i-i;j++){
            if (!cmp(arr[j],arr[j+1])){
                swap(arr[j],arr[j+1]);

            }
        }
    }

    // make a queue for traversing the node
    queue<Node> Q;
    Node u, v;

    // dummy node at starting
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);


    //Extract items from decision tree and compute the profit of all its child nodes and update maxProfit
    int maxProfit = 0;
    while (!Q.empty())
    {
        // Dequeue a node
        u = Q.front();
        Q.pop();

        // For root node, assign level 0
        if (u.level == -1)
            v.level = 0;

        // Next iteration if there are no nodes on next level 
        if (u.level == n - 1)
            continue;

        //if it is not the last node, then increment level and compute profit of child nodes
        v.level = u.level + 1;


        //Update the values of weight and value 
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;


        //If total weight is less than W and profit is greater than previous profit, update max profit
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        //Calculate bound to decide whether to add v to Q
        v.bound = bound(v, n, W, arr);

        // If bound value is greater than profit then push into queue
        
        if (v.bound > maxProfit)
            Q.push(v);

        // Not selecting the item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}


int main()
{
    int W = 10; // Weight of knapsack
    Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    //Items represented as (weight,value)
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible profit = "
         << knapsack(W, arr, n);

    return 0;
}