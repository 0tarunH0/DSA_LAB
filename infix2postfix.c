#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20

char postfix[SIZE];

struct stack{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, char item)
{
    if (s->top == SIZE - 1) {
        return;
    }
    s->data[++(s->top)] = item;
}

char pop(STACK *s)
{
    if (s->top == -1) {
        return '\0';
    }
    return s->data[(s->top)--];
}

int preced(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        default: return -1;
    }
}

void infixtopostfix(STACK *s, char infix[SIZE])
{
    int i, j = 0;
    char symbol;

    for(i = 0; infix[i] != '\0'; i++)
    {
        symbol = infix[i];

        if(isalnum(symbol))
            postfix[j++] = symbol;
        else
        {
            switch(symbol)
            {
                case '(':
                    push(s, symbol);
                    break;

                case ')':
                    while(s->top != -1 && s->data[s->top] != '(')
                    {
                        postfix[j++] = pop(s);
                    }
                    if (s->top != -1 && s->data[s->top] == '(') {
                        pop(s);
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(s->top != -1 && s->data[s->top] != '(' && preced(s->data[s->top]) >= preced(symbol))
                    {
                        postfix[j++] = pop(s);
                    }
                    push(s, symbol);
                    break;

                default:
                    break;
            }
        }
    }

    while(s->top != -1)
    {
        if (s->data[s->top] == '(') {
            pop(s);
        } else {
            postfix[j++] = pop(s);
        }
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[SIZE];
    STACK s;
    s.top = -1;

    printf("\nRead infix expression (max 19 chars, no spaces):\n");
    scanf("%19s", infix);

    infixtopostfix(&s, infix);

    printf("\nPostfix expression is: %s\n", postfix);

    return 0;
}
