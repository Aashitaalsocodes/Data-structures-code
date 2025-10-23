#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
            int r,f;
            int data[SIZE]
            }QUEUE;
//INSERTION(ENQUEUE)

void Enqueue(QUEUE *q, int item){
    if(q->r == SIZE-1)
        printf("\nQueue full");
            else{
                  q->r = q->r+1;
                  q->data[q->r]=item;
                  if(q->f == -1)
                    q->f=0;
            }
            }

//DELETION

void DeQueue(QUEUE *q)
{
    if(q -> f == -1)
    printf("\n Queue is empty");
    else{
        printf("\n element deleted is %d", q->data[q->r]);
        if(q->f == q->r){

            q-> f= -1;
            q-> r= -1;
            }
        else {

             q-> f= q-> f+1;
        }

    }
}
// DISPLAY
void display(QUEUE q)
{
    int i;
    if(q.f==-1)
    printf("\n queue is empty");
    else{
        printf("\n stack content are \n ");
        for(i=q.f;i<=q.r;i++)
        printf("%d\n",q.data[i]);
    }
}
   int main()
   {
   int ch,item;
   QUEUE q;

   q.f = -1;
   q.r = -1;
   for (;;)

{
    printf("\n 1.insert");
    printf("\n 2.delete");
    printf("\n 3.display");
    printf("\n 4.exit");
    printf("\n Read choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\n read element to be inserted:");
                scanf("%d",&item);
                Enqueue(&q, item);
                break;
        case 2: DeQueue(&q);
                break;
        case 3: display(q);
                break;
        default: exit(0);
    }
}
    return 0;
}

