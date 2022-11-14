#include "linked_list.cpp" //own linked list class
#include <bits/stdc++.h>
using namespace std;

node* reverse (node * &head){
    node * prevptr = NULL;
    node * currentptr = head;
    node * nextptr;

    while (currentptr!=NULL){
        nextptr=currentptr->next; //initialising nextptr within loop
        currentptr->next = prevptr;

        prevptr=currentptr; //moving both pointers forward
        currentptr=nextptr;
    }

    return prevptr;
}

int main(){

    node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    display(head);
    cout<<endl;
    node* reverse_head = reverse(head);

    display(reverse_head);

}