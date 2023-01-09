//give all solutions to the n queens problem

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int count = 0;

bool safe(int k, vector<int> &x) {
    for (int i = 1; i < k; i++)
        if ((x[i] == x[k]) || (abs(x[i] - x[k]) == abs(i - k)))
            return false;
    return true;
}

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
            if (k == n)
                print(x);
            else
                nqueens(k + 1, n, x);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<int> x(n + 1);
    nqueens(1, n, x);
    return 0;
}

