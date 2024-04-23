#include <iostream>
#include <vector>
using namespace std;

int main() {
    int x;
    cin>>x;

    vector<int> values;
    for (int i=0;i<10;i++) {
        int inp;
        cin>>inp;
        values.push_back(inp);
    }

    vector<int> digits;

    while (x>0) {
        int d = x%10;
        digits.push_back(d);
        x/=10;
    }

    for (int i=0;i<digits.size();i++) {
        digits[i] = max(digits[i], values[digits[i]]);
    }

    for (int i=digits.size()-1;i>=0;i--) {
        cout<<digits[i];
    }
}