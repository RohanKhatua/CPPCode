#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

class Node
{
public:
    Node *l_child;
    Node *r_child;
    int value;

    Node(Node *l_child, Node *r_child, int value)
    {

        this->l_child = l_child;
        this->r_child = r_child;
        this->value = value;
    }
};

void insert_node(int item, Node *root_ptr)
{
    bool flag = false;

    Node obj = Node(nullptr, nullptr, 0);
    Node *ptr1 = &obj;
    bool make_new_node = false;

    while (root_ptr != nullptr && !flag)
    {
        if (item < root_ptr->value)
        {
            ptr1 = root_ptr;
            root_ptr = root_ptr->l_child;
        }
        else if (item > root_ptr->value)
        {
            ptr1 = root_ptr;
            root_ptr = root_ptr->r_child;
        }
        else
            flag = true;
    }

    if (root_ptr == nullptr)
    {
        make_new_node = true;
    }

    if (make_new_node)
    {
        if (ptr1->value < item)
        {
            Node node = Node(nullptr, nullptr, item);
            ptr1->r_child = &node;
        }
        else
        {
            Node node = Node(nullptr, nullptr, item);
            ptr1->l_child = &node;
        }
    }
}

Node *successor(Node *p)
{
    Node *ptr1 = p->r_child;
    if (ptr1 != nullptr)
    {
        while (ptr1->l_child != nullptr)
        {
            ptr1 = ptr1->l_child;
        }
    }

    return ptr1;
}

void delete_node(int item, Node *root_ptr)
{
    Node *copy_root_ptr = root_ptr;
    bool flag = false;
    Node *parent;
    while (root_ptr != nullptr && !flag)
    {
        if (item < root_ptr->value)
        {
            parent = root_ptr;
            root_ptr = root_ptr->l_child;
        }
        else if (item > root_ptr->value)
        {
            parent = root_ptr;
            root_ptr = root_ptr->l_child;
        }
        else
            flag = true;
    }
    if (flag)
    {
        int case_num;
        if (root_ptr->l_child == nullptr && root_ptr->r_child == nullptr)
        {
            case_num = 1;
        }
        else if (root_ptr->l_child != nullptr && root_ptr->r_child != nullptr)
        {
            case_num = 3;
        }
        else
            case_num = 2;

        if (case_num == 1)
        {
            if (parent->l_child == root_ptr)
            {
                parent->l_child = nullptr;
            }
            else
                parent->r_child = nullptr;
        }

        else if (case_num == 2)
        {
            if (parent->l_child == root_ptr)
            {
                if (root_ptr->l_child == nullptr)
                {
                    parent->l_child = root_ptr->r_child;
                }
                else
                {
                    parent->l_child = root_ptr->l_child;
                }
            }
            else if (parent->r_child == root_ptr)
            {
                if (root_ptr->l_child == nullptr)
                {
                    parent->r_child = root_ptr->r_child;
                }
                else
                {
                    parent->r_child = root_ptr->l_child;
                }
            }
        }

        else
        {
            Node *ptr1 = successor(root_ptr);
            int item1 = ptr1->value;
            delete_node(item1, root_ptr);
            root_ptr->value = item;
        }
    }
    else
    {
        cout << "Item does not exist";
    }
}

int main()
{
    Node root = Node(nullptr, nullptr, 15);
    Node *root_ptr = &root;

    while (true)
    {
        cout << "Press 1 to enter, 2 to delete. Press 3 to exit";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int item;
            cout << "Enter the item to be inserted : ";
            cin >> item;
            insert_node(item, root_ptr);
        }

        else if (choice == 2)
        {
            int item;
            cout << "Enter the item to be deleted : ";
            cin >> item;
            delete_node(item, root_ptr);
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "Please enter a valid choice : " << endl;
        }
    }
}