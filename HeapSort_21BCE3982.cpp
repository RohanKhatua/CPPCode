#include <bits/stdc++.h>
using namespace std;

void print_as_tree(int* a, int n, int i, int indent) {
    if (i >= n) return;
    print_as_tree(a, n, 2*i+2, indent+4);
    cout << string(indent, ' ') << a[i] << endl;
    print_as_tree(a, n, 2*i+1, indent+4);
}

void printArray(int* a, int n){
    for(int i=0; i<n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

void heapify(int* a, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest=0;
    if (l<n && a[l]>a[i]){
        largest=l;
    }
    else largest=i;
    if (r<n && a[r]>a[largest]){
        largest = r;
    }
    if (largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

void buildHeap(int* a, int n){
    cout<<"Build Heap : "<<endl;
    cout<<"------------------"<<endl;
    for (int i=(n-1)/2;i>=0;i--){
        heapify(a,n,i);
        print_as_tree(a,n,0,0);
        cout<<endl; 
        cout<<"------------------"<<endl;
    }
}

void heapsort(int* a, int n){
    buildHeap(a,n);
    int size=n;
    cout<<"Heap Sort : "<<endl;
    cout<<"------------------"<<endl;
    for (int i=n-1;i>=1;i--){
        cout<<"i = "<<i<<endl;
        swap(a[0],a[i]);
        size--;
        heapify(a,size,0);
        print_as_tree(a,n,0,0);
        cout<<"---------------"<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter Size of array : ";
    cin>>n;
    int a[n];

    cout<<"Enter the elements of the array : "<<endl;


    for(int i=0;i<n;i++){
        cin>>a[i];
        cout<<"Current Tree : "<<endl;
        print_as_tree(a,i+1,0,0);
        cout<<"---------------"<<endl;
    }

    

    heapsort(a,n);
    cout<<"The Sorted Array is : "<<endl;
    printArray(a,n);
}