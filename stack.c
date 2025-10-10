#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct stack{
int top;
int data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,int item)
{
    if(s->top==SIZE-1)
        printf("\n Stack is overflow\n");
    else{
        s->top=s->top+1;
        s->data[s->top]=item;
    }
}
void pop(STACK *s){
 if(s->top==-1)
    printf("\n Stack is underflowing\n");
 else{
    printf("Element poped is %d",s->data[s->top]);
    s->top=s->top-1;
 }
}
void display(STACK s){
 if(s.top==-1)
    printf("\n Stack is empty\n");
 else
{
    printf("\n stack content area\n");
    for(int i=s.top;i>=0;i--)
        printf("%d\n",s.data[i]);
}
}
int main()
{

    int ch,item;
    STACK s;
    s.top=-1;
    for(;;)
    {
        printf("\n1-push\n2-pop\n3-display\n4-exit");
        printf("\n Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\n Read the item to push : ");
            scanf("%d",&item);
            push(&s,item);
            break;
            case 2:pop(&s);
            break;
            case 3:display(s);
            break;
            default:exit(0);
        }
    }
return 0;
}
