#include <iostream>
using namespace std;

void print_as_tree(int *a, int n, int i, int indent) {
    if (i >= n) return;
    print_as_tree(a, n, 2*i+2, indent+4);
    cout << string(indent, ' ') << a[i] << endl;
    print_as_tree(a, n, 2*i+1, indent+4);
}

void min_heapify(int* a, int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest=0;
    if (l<n && a[l]<a[i]){
        smallest=l;
    }
    else smallest=i;
    if (r<n && a[r]<a[smallest]){
        smallest = r;
    }
    if (smallest!=i){
        swap(a[i],a[smallest]);
        min_heapify(a,n,smallest);
    }
}

void build_min_heap(int *a, int n){
    cout<<"Build Min Heap : "<<endl;
    for (int i=(n-1)/2;i>=0;i--){
        min_heapify(a,n,i);       
        print_as_tree(a,n,0,0);

        cout<<endl; 
        cout<<"------------------"<<endl;
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
        cout<<"------------------"<<endl;
    }

    cout<<"Initial Heap : "<<endl;

    print_as_tree(a,n,0,0);

    build_min_heap(a,n);

    cout<<"Min heap is : "<<endl;
    print_as_tree(a,n,0,0);

}