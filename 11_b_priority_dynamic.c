//Priority Queue Dynamic Memory Allocation

#include<stdio.h>
#include<stdlib.h>

struct q
{
    int f,r,n,*a;
};
void create(struct q *q)
{
    printf("Enter size of queue : ");
    scanf("%d",& q->n);
    q->a=malloc((q->n)*sizeof(int));
    q->f=0;
    q->r=-1;
}
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
void insert(struct q *q,int k)
{
    int j;
    if(q->r==(q->n)-1)
    {
        printf("Queue Full\n");
        printf("Allocating Memory Dynamically\n");
        int *t = realloc(q->a,2*(q->n)*sizeof(int));
        q->r=q->n-1;
        q->n=2*q->n;
        q->a=t;
    }
    j = q->r;
    while(j>=0 && k<q->a[j])
    {
        q->a[j+1]=q->a[j];
        j--;
    }
    q->a[j+1] = k;
    q->r++;
}
void del(struct q *q)
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
void main()
{
    struct q *q=malloc(sizeof(struct q));
    create(q);
    int k,ch;
    while(1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to insert : ");
                   scanf("%d",&k);
                   insert(q,k);
                   break;
            case 2:del(q);
                   break;
            case 3:disp(q);
                   break;
            case 4:exit(0);
            default:printf("Invalid choice !!\n");
        }
    }
}