#include <bits/stdc++.h>
using namespace std;

int getPartition(int *a, int n) {
    vector<int> left;
    vector<int> right;

    for (int part_pos=0;part_pos<n;part_pos++) {
        for (int i=0;i<n;i++) {
            if (i<=part_pos) {
                left.push_back(a[i]);
            }
            else right.push_back(a[i]);
        }
        int left_max = *max_element(left.begin(),left.end());
        int right_min = *min_element(right.begin(),right.end());

        if (left_max<=right_min) return part_pos;
        left.clear();
        right.clear();
    }

    return 0;
}

int main(){
    cout<<"Enter number of elements : ";
    int n;
    cin>>n;

    int a[n];

    cout<<"Enter the array elements"<<endl;
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    int partition = getPartition(a,n);

    cout<<"Partition Index : "<<partition;
}