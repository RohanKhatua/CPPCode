#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

int getPriorityNumber(char c)
{
    if (c == '-' || c == '+')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

bool isEmpty(int top){
    return top==-1;
}


void pop_no_return(char stack[], int &top){
    top--;
}

void push(char stack[],int &top, char element){
    stack[top+1]=element;
    top++;
}

string infixToPrefix(string infix)
{

    int l = infix.size();

    
    reverse(infix.begin(), infix.end());


    for (int i = 0; i < l; i++) {

        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }



    infix = '(' + infix + ')';
    l= infix.size();
    char stack[1000];
    string prefix;

    int top=-1;

    for (int i = 0; i < l; i++) {


        if (isalpha(infix[i]) || isdigit(infix[i]))
            prefix += infix[i];


        else if (infix[i] == '(')
            push(stack,top,'(');


        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                prefix += stack[top];
                pop_no_return(stack,top);
            }


            pop_no_return(stack,top);
        }

        else
        {
            if (isOperator(stack[top]))
            {
                if(infix[i] == '^')
                {
                    while (getPriorityNumber(infix[i]) <= getPriorityNumber(stack[top]))
                    {
                        prefix += stack[top];
                        pop_no_return(stack,top);
                    }

                }
                else
                {
                    while (getPriorityNumber(infix[i]) < getPriorityNumber(stack[top]))
                    {
                        prefix += stack[top];
                        pop_no_return(stack,top);
                    }

                }

                push(stack,top,infix[i]);
            }
        }
    }
    while(!isEmpty(top)){
        prefix += stack[top];
        pop_no_return(stack,top);
    }


    reverse(prefix.begin(), prefix.end());

    return prefix;
}


int main()
{
    string expression;
    cout<<"Enter infix expression : "<<endl;
    cin>>expression;


    cout << infixToPrefix(expression) << endl;
  
}

