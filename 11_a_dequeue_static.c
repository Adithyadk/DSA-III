//Dequeue Queue Static Memory Allocation

#include<stdio.h>
#include<stdlib.h>

struct q
{
    int f,r,n,a[10];
};

void disp(struct q *q)
{
    if(q->f>q->r)
       printf("Queue Empty\n");
    else
    {
        printf("Queue : ");
        for(int i=q->f;i<=q->r;i++)
        {
           printf("%d\t",q->a[i]);
        }
    }
    printf("\n");
}

void insertrear(struct q *q,int k)
{
    if(q->r==(q->n)-1)
        printf("Queue Full\n");
    else
      q->a[++q->r]=k;
}

void insertfront(struct q *q,int k)
{
    if(q->f==0)
        printf("Front Insertion Not Possible\n");
    else 
        q->a[--q->f] = k; 
}

void delfront(struct q *q)
{
    if(q->f>q->r)
    {
        printf("Deletion complete!! Queue empty\n");
        q->f=0;q->r=-1;
    }
    else
    {
       printf("Deleted element is: %d\n",q->a[q->f]);
       q->f++;
    }
}

void delrear(struct q*q)
{
    if(q->f>q->r)
    {
        printf("Deletion complete!! Queue empty\n");
        q->f=0;q->r=-1;
    }
    else
    {
    printf("Deleted element is: %d\n",q->a[q->r]);
    q->r--;
    }
}

void main()
{
    struct q *q=malloc(sizeof(struct q));
    printf("Enter size of queue : ");
    scanf("%d",&q->n);
    q->f=0,q->r=-1;
    int k,ch;
    while(1)
    {
        printf("\n1.Insertion Rear\n2.Deletion Front\n3.Insertion Front\n4.Deletion Rear\n5.Display\n6.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to insert : ");
                   scanf("%d",&k);
                   insertrear(q,k);
                   break;
            case 2:delfront(q);
                   break;
            case 3:printf("Enter element to insert : ");
                   scanf("%d",&k);
                   insertfront(q,k);
                   break;
            case 4:delrear(q);
                   break;
            case 5:disp(q);
                   break;
            case 6:exit(0);
            default:printf("Invalid choice !!\n");
        }
    }
}