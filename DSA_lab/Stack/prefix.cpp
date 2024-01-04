// Implementation of program to convert infix expression to prefix expression

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *S;

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
        S = new int[size];
    }

    void push(int x);
    int pop();
    int isEmpty();
    int isFull();
    int stackTop();
    int isOperand(char x);
    int precedence(char x);
    char *InToPre(char *infix);
    
};

void Stack::push(int x)
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

int Stack::pop()
{
    int x = -1;
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

char *Stack::InToPre(char *infix)
{
    int i = 0, j = 0;
    char *prefix;
    int len = strlen(infix);
    prefix = new char[len + 1];
    Stack stk(len);
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            prefix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(stk.stackTop()))
            {
                stk.push(infix[i++]);
            }
            else
            {
                prefix[j++] = stk.pop();
            }
        }
    }
    while (!stk.isEmpty())
    {
        prefix[j++] = stk.pop();
    }
    prefix[j] = '\0';
    reverse(prefix, prefix + len);
    return prefix;
}

int main()
{
    char infix[] = "a+b*c-d/e";
    Stack stk(strlen(infix));
    cout << "Prefix: " << stk.InToPre(infix) << endl;
    return 0;
}



