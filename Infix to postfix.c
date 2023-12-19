/*
C program to convert Infix to postfix expression conversion using array as a stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char stack[max];
char infix[max], postfix[max];
int top = -1;

void push(char data)
{
    if (top == max - 1)
    {
        printf("\nStack overflow !!");
    }
    else
    {
        ++top;
        stack[top] = data;
    }
}

char pop()
{
    char data;
    if (top == -1)
    {
        printf("\nStack underflow !!");
    }
    else
    {
        data = stack[top];
        --top;
        return data;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isSpace(char data)
{
    if (data == ' ' || data == '\t')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char x)
{
    switch (x)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

void inTOpo()
{
    int j = 0;

    for (int i = 0; i < strlen(infix); i++)
    {
        int symbole = infix[i];
        if (!isSpace(symbole))
        {
            switch (symbole)
            {
            case '(':
                push(symbole);
                break;

            case ')':
                int peek;
                while ((peek = pop()) != '(')
                {
                    postfix[j++] = peek;
                }
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (!isEmpty && (precedence(symbole) <= precedence(stack[top])))
                {
                    postfix[j++] = pop();
                }
                push(symbole);
                break;

            default:
                postfix[j++] = symbole;
                break;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

void main()
{
    printf("\nInfix : ");
    gets(infix);

    inTOpo();

    printf("\nPostfix : ");
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        printf("%c", postfix[i]);
    }
}
