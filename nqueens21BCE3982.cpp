#include <bits/stdc++.h>
using namespace std;

int count = 0;

//Function which checks if a queen can be placed at a given position
bool safe(int k, vector<int> &x) {
    for (int i = 1; i < k; i++)
        if ((x[i] == x[k]) || (abs(x[i] - x[k]) == abs(i - k)))
            return false;
    return true;
}

//Utility function to print the board
void print(vector<int> &x) {
    int n = x.size() - 1;
    cout << "Solution #" << ++count << ":" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (x[i] == j)
                cout << "Q ";
            else
                cout << "* ";
        cout << endl;
    }
    cout << endl;
}

void nqueens(int k, int n, vector<int> &x) {
    for (int i = 1; i <= n; i++) {
        x[k] = i;
        if (safe(k, x)) {
            if (k == n) //if we reach the last row, all the queens have been placed
                print(x);
            else
                nqueens(k + 1, n, x);
                //recursive call to next case
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<int> x(n + 1);
    nqueens(1, n, x);
    if (count == 0)
        cout << "No solution" << endl;
    return 0;
}

