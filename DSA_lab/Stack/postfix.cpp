// Program to convert infix expression to postfix expression

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *S;

    Stack()
    {
        size = 0;
        top = -1;
        S = NULL;
    }

    Stack(int size)
    {
        this->size = size;
        top = -1;
        S = new char[size];
    }

    void push(char x);
    char pop();
    int isEmpty();
    int isFull();
    int stackTop();
    int isOperand(char x);
    int precedence(char x);
    char *InToPost(char *infix);
};

void Stack::push(char x)
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        S[top] = x;
    }
}

char Stack::pop()
{
    char x = '0';
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

int Stack::isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

int Stack::isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int Stack::stackTop()
{
    if (top == -1)
    {
        return -1;
    }
    return S[top];
}

int Stack::isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    return 1;
}

int Stack::precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}

char *Stack::InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len + 1];

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop()))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[] = "a+b*c-d/e";
    Stack stk;
    stk.size = strlen(infix);
    stk.top = -1;
    stk.S = new char[stk.size];

    char *postfix = stk.InToPost(infix);
    cout << postfix << endl;

    return 0;
}