#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int *s; 
};
void create(struct stack *st)
{
    printf("Enter the size :\t");
    scanf("%d",&st->size);
    st->top=-1;
    st->s =(int*)malloc(sizeof(int)*st->size); 
}
void pop(struct stack *st )
{
    int y;
    if(st->top==-1)
        printf("Stack Underflow\n");
    else
    {
        y=st->s[st->top];
        st->top--;
        printf("\n%d is the popped element\n",y);
    }
}
void push(struct stack *st,int n)
{
    if(st->top==st->size-1)
    { 
        printf("Stack Overflow\n");
        printf("Allocating Memory Dynamically\n");
        int *temp = realloc(st->s,2*(st->size)*sizeof(int));
        st->s = temp;
        st->size =st->size*2;
    }
        st->top++;
        st->s[st->top]=n;
}

void display(struct stack *st)
{
    int i;
    for(i=st->top;i>=0;i--)             //(i=0;i<=st->top;i++)
        printf("%d\n",st->s[i]);
}

void main()
{
    struct stack *st = malloc(sizeof(struct stack)) ;    
    int ch,n;
    create(st);
    while(1)
     {
         printf("\n1.Push\n2.Display\n3.Pop\n4.exit\n");
         printf("Enter your choice:\t ");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
                    printf("\nEnter the element\n");
                    scanf("%d",&n);
                    push(st,n);
                    break;
            case 2:
                    display(st);
                    break;
            case 3:
                   pop(st);
                   break;
            case 4:
                   exit(0);
                   break;
            default:
                   printf("Invalid choice\n");
         }
     }
}    