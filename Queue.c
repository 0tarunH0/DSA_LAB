#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue{
int front,rear;
int data[SIZE];
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item)
{
    if (q->rear==SIZE-1)
        printf("\nQueue overflow\n");
    else{
        q->rear++;
        q->data[q->rear]=item;
        if(q->front==-1)
            q->front=0;
        printf("\nInseter %d into queue\n",item);
    }
}
void dequeue(QUEUE *q)
{
    if (q->front==-1)
        printf("\nQueue underflow\n");
    else{
        printf("\nDeleted element is %d\n",q->data[q->front]);
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
        }else
        {
            q->front++;
        }
    }
}void display(QUEUE q)
{
    printf("\nQueue contents are :\n");
    for(int i=q.front;i<=q.rear;i++)
        printf("%d\t",q.data[i]);
    printf("\n");
}
int main()
{

    int ch,item;
    QUEUE q;
    q.front=-1;
    q.rear=-1;
    while(1)
    {
        printf("\n------Queue Operations-------");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\n---------------------------------------------");
        printf("\n Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element to insert: ");
            scanf("%d",&item);
            enqueue(&q,item);
            break;
            case 2:dequeue(&q);
            break;
            case 3:display(q);
            break;
            case 4:printf("\nExiting\n");
            exit(0);
            default :printf("\nInvalid choice!\n");
        }
    }
return 0;
}
