#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define SIZE 20

struct stack{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, float item)
{
    if (s->top == SIZE - 1) {
        printf("\nError: Stack Overflow. Expression is too complex.\n");
        exit(1);
    }
    s->data[++(s->top)] = item;
}

float pop(STACK *s)
{
    if (s->top == -1) {
        printf("\nError: Stack Underflow. Invalid postfix expression.\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

float compute(float opr1, char symbol, float opr2)
{
    switch(symbol)
    {
        case '+': return opr1 + opr2;
        case '-': return opr1 - opr2;
        case '*': return opr1 * opr2;
        case '/':
            if (opr2 == 0) {
                printf("\nError: Division by zero.\n");
                exit(1);
            }
            return opr1 / opr2;
        case '^': return pow(opr1, opr2);
        default:
            printf("\nError: Invalid operator %c\n", symbol);
            exit(1);
    }
}

float evaluate(STACK *s, char postfix[20])
{
    float opr1, opr2, res, final_result;
    int i;
    char symbol;

    for(i = 0; postfix[i] != '\0'; i++)
    {
        symbol = postfix[i];

        if(isdigit(symbol))
        {
            push(s, (float)(symbol - '0'));
        }
        else
        {
            opr2 = pop(s);
            opr1 = pop(s); 
            
            res = compute(opr1, symbol, opr2);
            push(s, res);
        }
    }

    final_result = pop(s); 

    if (s->top != -1)
    {
        printf("\nError: Invalid postfix expression. Too many operands.\n");
        exit(1);
    }

    return final_result;
}

int main()
{
    char postfix[20];
    float ans;
    STACK s;
    s.top = -1;

    printf("\nRead postfix expression (single digits only, no spaces):\n");
    scanf("%s", postfix);

    ans = evaluate(&s, postfix);

    printf("\nFinal result is %f\n", ans);
    return 0;
}
