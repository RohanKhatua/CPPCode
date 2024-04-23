#include <bits/stdc++.h> 
using namespace std;

int main() {
    int x;
    cin>>x;

    int cnt = 0;
    while (x>1) {
        int half = x/2;
        for(int fact = half; fact>=1;fact--) {
            if (x%fact==0) {
                x-=fact;
                cnt++;
                break;
            }
        }
    }

    cout<<cnt+2;
}