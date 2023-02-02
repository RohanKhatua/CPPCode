#include <bits/stdc++.h>

using namespace std;


class Item {
public:
    int weight;
    int value;
    Item(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};

bool compareItems (Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

void printItem(Item item){
    cout<<"Weight : "<<item.weight<<" Value : "<<item.value<<endl;
}

vector<int> knapsack(vector<int> w, vector<int> v, int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    vector<vector<int>> sol(n + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i - 1] <= j) {
                if (v[i - 1] + dp[i - 1][j - w[i - 1]] > dp[i - 1][j]) {
                    dp[i][j] = v[i - 1] + dp[i - 1][j - w[i - 1]];
                    sol[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int i = n, j = W;
    vector<int> items(n);
    while (i > 0 && j > 0) {
        if (sol[i][j] == 1) {
            items[i - 1] = 1;
            j -= w[i - 1];
        }
        i--;
    }
    return items;
}

int main() {
    cout<<"Enter number of items : ";
    int n;
    cin>>n;
    cout<<"Enter capacity of knapsack : ";
    int W;
    cin>>W;    

    vector<Item> items;
    for (int i=0;i<n;i++)
    {
        int weight, value;
        cout<<"Enter weight and value of item "<<i+1<<" : ";
        cin>>weight>>value;
        items.push_back(Item(weight, value));
    }

    sort(items.begin(), items.end(), compareItems);

    cout<<"Items in decreasing order of value/weight ratio : "<<endl;
    int c=1;
    for (Item item : items){
        cout<<c++<<" : ";
        printItem(item);
    }

    vector<int> w(n);
    vector<int> v(n);
    for (int i=0;i<n;i++)
    {
        w[i] = items[i].weight;
        v[i] = items[i].value;
    }

    vector<int> itemSolution = knapsack(w, v, n, W);
    int totalProfit  = 0;
    cout << "Items Chosen : "<<endl;
    for (int i = 0; i < n; i++) {
        if (itemSolution[i] == 1) {
            cout << i + 1 << " ";
            totalProfit += items[i].value;
        }
    }
    cout<<"Total Profit : "<<totalProfit;
    return 0;
}
