#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#define SIZE 20
struct stack{
int top;
float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,float item)
{
    s->data[++(s->top)]=item;
}
float pop(STACK *s)
{
    return s->data[(s->top)--];
}
float compute(float opr1,char symbol,float opr2)
{
    switch(symbol)
    {
        case '+':return opr1+opr2;
        case '-':return opr1-opr2;
        case '*':return opr1*opr2;
        case '/':return opr1/opr2;
        case '^':return pow(opr1,opr2);
        }
}
float evaluate(STACK *s,char postfix[15])
{
    float opr1,opr2,res;
    int i;
    char symbol;
    for(i=0;postfix!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            push(s,symbol-'\0');
        else
        {
            opr2=pop(s);
            opr1=pop(s);
            res=compute(opr1,symbol,opr2);
            push(s,res);
        }
    }
    return pop(s);
}
int main()
{
    char postfix[20];
    float ans;
    STACK s;
    s.top=-1;
    printf("\nRead postfix expression:\n");
    scanf("%s",postfix);
    ans=evaluate(&s,postfix);
    printf("\nFinal result is %f",ans);
    return 0;
}
