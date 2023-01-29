//Circular Queue Static Memory Allocation
#include<stdio.h>
#include<stdlib.h>
struct que
{  
    int f,r,n,c,a[10];
};
void disp(struct que *q)
{
    
    if(q->c==0)
        printf("Queue Empty\n");
    else if(q->c>0)
    {
        int i=q->f;
        printf("Circular Queue : ");
       while(i!=q->r)     
        {  
           printf("%d\t",q->a[i]);
           i=(i+1)%q->n;
        }
    printf("%d\t\n",q->a[q->r]);
    }
}
void insert(struct que *q,int k)
{
    if(q->c==q->n)
        printf("Queue Full\n");
    else
    {
        q->r=(q->r+1)%q->n;
        q->a[q->r]=k;
        q->c++;
    }
}
void del(struct que *q)
{
    if(q->c==0)
    {
        q->r=-1;q->f=0;
        printf("Deletion complete!! Queue empty\n");
    }
    else
    {
        printf("Deleted element is: %d\n",q->a[q->f]);
        q->f=(q->f+1)%q->n;
        q->c--;
    }
}
void main()
{
    struct que *q=malloc(sizeof(struct que));
    printf("Enter size of queue : ");
    scanf("%d",&q->n);
    q->f=0,q->r=-1,q->c=0;
    int k,ch;
    while(1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter choice : ");
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
            default:printf("Invalid Choice\n");
        }
    }
}