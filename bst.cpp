#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* l_child;
    Node* r_child;

    explicit Node(int data){
        this->data=data;
        l_child=nullptr;
        r_child=nullptr;
    }
};

bool search (Node* root, int key){
    if (key<root->data){
        if (root->l_child==nullptr){
            return false;
        }
        else search(root->l_child, key);
    }

    else if (key>root->data){
        if (root->r_child==nullptr){
            return false;
        }
        else search(root->r_child, key);
    }

    return true;
}

pair<Node*,Node*> search_with_ptr (Node* root, int key){
    //returns pointer to parent node
    Node* ptr = root;
    Node* ptr1 = new Node(0);

    while (ptr!=nullptr){        
        if (key<ptr->data){
            ptr1=ptr;
            ptr=ptr->l_child;
        }
        else if (key>ptr->data){
            ptr1=ptr;
            ptr=ptr->r_child;
        }
        else return make_pair(ptr, ptr1);
    }

    return make_pair(nullptr, ptr1);
}

void insert(Node* &root, int data){
    if (data<root->data){
        if (root->l_child!= nullptr){
            insert(root->l_child, data);
        }
        else {
            Node* to_insert = new Node(data);
            root->l_child=to_insert;
        }
    }

    else if (data>root->data){
        if (root->r_child!= nullptr){
            insert(root->r_child, data);
        }
        else {
            Node* to_insert = new Node(data);
            root->r_child=to_insert;
        }
    }

    else {
        cout<<"Value already present in BST";
    }

    

}

// void delete (Node* &root, int key){

// }

int main(){

    Node* root = new Node(5);
    insert(root, 6);
    cout<<(search(root, 6)?"True" : "False")<<endl;
    cout<<search_with_ptr(root, 6).first->data;
    cout<<search_with_ptr(root, 6).second->data;

    return 0;
}