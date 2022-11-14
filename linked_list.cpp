/**
 * Class is used as utility for all other linked list classes 
 * it defines the functions insertAtHead, insertAtTail, deletion and display
 * it defines the custom data type node
*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void deletion(node *&head, int val)
{

    // head node to be deleted
    if (head->data == val)
    {
        //only head node exists
        if (head->next==NULL){
            head = NULL;
            return;
        }
        node *to_delete = head;
        head = head->next;
        delete to_delete;
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
}

void display(node *&head)
{

    if (head == NULL)
    {
        cout << "Linked List is empty";
        return;
    }

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "=>";
        temp = temp->next;
    }
    cout << "NULL";
}

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void insertAtHead(node * &head, int val){

    node* n = new node(val);
    if (head==NULL){
        head=n;
    }
    else {
        n->next=head;
        head = n;
    }
}

// int main()
// {
//     node *head = NULL;

//     insertAtTail(head, 10);
//     // insertAtTail(head, 20);
//     // insertAtTail(head, 30);
//     // insertAtTail(head, 40);
//     // insertAtTail(head, 50);

//     // insertAtHead(head, 100);

//     // display(head);
//     // cout << endl;

//     // deletion(head, 50);

//     display(head);
//     cout<<endl;

//     deletion(head, 10);
//     display(head);

// }