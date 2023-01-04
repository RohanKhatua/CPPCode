#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

//Class to represent an item which stores weight and corresponding value of Item
class Item {
public:
    float profit;
    float weight;

    Item() {
        this->profit = 0;
        this->weight = 0;
    }

    Item(float profit, float weight) {
        this->profit = profit;
        this->weight = weight;

    }
};

//A comparator function used to sort Item according to val/weight ratio
bool compareItems(Item a, Item b) {
    return (float) a.profit / a.weight < (float) b.profit / b.weight;
}

//Function to print Item
void printItem(Item a) {
    float pw_ratio = a.profit / (float)a.weight;
    cout << "Profit : " << a.profit << " Weight : " << a.weight << " Ratio : " << pw_ratio << endl;
}

//Insertion Sort technique to sort Item according to val/weight ratio
void insertionSort(vector<Item> &items, int n) {
    for (int i = 1; i < n; i++) {
        Item key = items[i];
        int j = i - 1;
        while (j >= 0 && compareItems(items[j], key)) {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = key;
    }
}


int main() {

    float capacity;
    int n;

    cout << "Enter Capacity of Knapsack : ";
    cin >> capacity;
    cout << "Enter Number of Items : ";
    cin >> n;

    vector<Item> items(n);


    cout << "Enter Profits : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit;
    }

    cout << "Enter Weights : " << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }

    insertionSort(items, n);

    cout<<"Items arranged in decreasing order of profit/weight ratio : "<<endl;
    for (Item x: items)
        printItem(x);

    vector<float> x(n);

    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    int i = 0;

    //Taking whole items 

    for (i = 0; i < n; i++) {
        if (items[i].weight > capacity)
            break;
        else {
            x[i] = 1;
            capacity -= items[i].weight;
        }
    }

    //Taking fraction of last item
    if (i < n) {
        x[i] = capacity / items[i].weight;
        capacity -= x[i] * items[i].weight;
    }

    float total_profit =0;

    //Calculating total profit by multiplying profit of each item with fraction of that item
    for (int j=0;j<n;j++){
        total_profit+=(x[j]*items[j].profit);
    }

    //Printing the result
    cout<<"Amount of each item taken :"<<endl;

    for (int j = 0; j < n; j++)
        cout << "Item "<<j<<" : "<<x[j] << endl;

    cout<<"Total Profit : "<<total_profit<<endl;

    return 0;
}