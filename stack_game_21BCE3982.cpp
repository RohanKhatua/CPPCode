#include <iostream>
using namespace std;

bool isEmpty(int top){
    return top==-1;
}

int pop(int stack[],int &top){
    int x=stack[top];
    top--;
    return x;
}

void push(int stack[],int &top, int element){
    stack[top+1]=element;
    top++;
}


int main(){
    int n;

    cout<<"Enter number of elements in stack : "<<endl;
    cin>>n;

    int stack1[1000]={0};int stack2[1000]={0}; //space for pushing

    int top1=-1;
    int top2=-1;

    cout<<"Enter elements of stacks : "<<endl;

    for (int i = 0; i < n;i++){
        cin>>stack1[i];
        cin>>stack2[i];
        top1++;
        top2++;
    }

    while (!isEmpty(top1)&&!isEmpty(top2)){
        int n1=pop(stack1,top1);
        int n2=pop(stack2,top2);

        if (n1>n2){
            int diff=n1-n2;
            int num_elements=top1+1;
            if (diff>=num_elements) {
                top1=-1;
                break;
            }
            for (int i=0;i<diff;i++){
                int x=pop(stack1,top1);
                push(stack2,top2,x);
            }
        }

        if (n1<n2){
            int diff=n2-n1;
            int num_elements=top2+1;
            if(diff>=num_elements){
                top2=-1;
                break;
            }
            for (int i=0;i<diff;i++){
                int x=pop(stack2,top2);
                push(stack1,top1,x);
            }
        }

        

    }

    if (isEmpty(top1)) cout<<"Player 1 has won";
    else cout<<"Player 2 has won";

    
}