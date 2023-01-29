#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct stack
{
    int n,top,*a;
};
void create(struct stack *sp)
{
    printf("enter size of stack\n");
    scanf("%d",&sp->n);
    sp->a=malloc((sp->n)*sizeof(int));
    sp->top=-1;
}
int check(char s)
{
    switch(s)
    {
        case '(':
        case ')':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;
        case '^':
        case '$':return 3;
        default: return-1;
    }
}
int operate(int a,int b,char s)
{
    switch(s)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
        case '$': return pow(a,b);
    }
}
void postfix(struct stack *sp,char p[],char ans[])
{
    int i=0,j=0,c;
    while(i!=strlen(p))
    {
        c=check(p[i]);
        if(c==-1)
        {
            ans[j++]=p[i];
        }
        else
        {
            if(sp->a[sp->top]==')'||p[i]==')')
            {
                if(sp->a[sp->top]==')')
                   sp->top-=1;
                while(sp->a[sp->top]!='(')
                {
                    ans[j++]=sp->a[sp->top];
                    sp->top-=1;
                }
                sp->top-=1;
            }
            else
            {
                while((check(p[i])!=0)&&(check(p[i])<=check(sp->a[sp->top]))&&sp->top!=-1)
                {
                    ans[j++]=sp->a[sp->top];
                    sp->top-=1;
                }
                sp->a[++sp->top]=p[i];
            }
        }
        i++;
    }
    while(sp->top!=-1)
    {
        ans[j++]=sp->a[sp->top];

        
        sp->top-=1;
    }
    printf("Postfix is:\n");
    for(i=0;i<strlen(ans);i++)
        printf("%c",ans[i]);
    printf("\n");
}
void prefix(struct stack *sp,char p[],char ans[])
{
    int i=strlen(p)-1,j=0,c;
    while(i!=-1)
    {
        c=check(p[i]);
        if(c==-1)
        {
            ans[j++]=p[i];
        }
        else
        {
            if(sp->a[sp->top]=='('||p[i]=='(')
            {
                if(sp->a[sp->top]=='(')
                   sp->top-=1;
                while(sp->a[sp->top]!=')')
                {
                    ans[j++]=sp->a[sp->top];
                    sp->top-=1;
                }
                sp->top-=1;
            }
            else
            {
                while((check(p[i])!=0)&&(check(p[i])<check(sp->a[sp->top]))&&sp->top!=-1)
                {
                    if((check(p[i])==3) && (check(sp->a[sp->top])==3))
                    {
                        break;
                    }
                    else
                    {
                       ans[j++]=sp->a[sp->top];
                       sp->top-=1;
                    }
                }
                sp->a[++sp->top]=p[i];
            }
        }
        i--;
    }
    while(sp->top!=-1)
    {
        ans[j++]=sp->a[sp->top];
        sp->top-=1;
    }
    printf("Prefix is:\n");
    for(i=strlen(ans)-1;i>=0;i--)
        printf("%c",ans[i]);
    printf("\n");
}
void post_eva(struct stack *sp,char p[],int ch)
{
    int i,z,op1,op2;
    if(ch==1)
      i=0;
    else
      i=strlen(p)-1;
    sp->top=-1;
    char d[1];
    while(ch==1?i<strlen(p):i>=0)
    {
        if((p[i]>='a'&&p[i]<='z')||(p[i]>='A'&&p[i]<='Z'))
        {
            printf("enter the value of %c: ",p[i]);
            scanf("%s",d);
            p[i]=d[0]-'0';
        }
        ch==1?i++:i--;
    }
    i=0;
    while(i!=strlen(p))
    {
        z=check(p[i]);
        if(z==-1)
            sp->a[++sp->top]=p[i];
        else if(z!=0)
        {
            op2=sp->a[sp->top--];
            op1=sp->a[sp->top];
            if(ch==1)
               sp->a[sp->top]=operate(op1,op2,p[i]);
            else
               sp->a[sp->top]=operate(op2,op1,p[i]);
        }
        i++;
    }
    printf("Evaluation is: %d\n",sp->a[0]);
}
void main()
{
    struct stack *sp=malloc(sizeof(struct stack));
    create(sp);
    char p[20];
    char ans[20];
    char a[20];
    int ch;
    while(1)
    {
        printf("1.Infix to postfix\n2.Infix to prefix\n3.Exit\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the expression\n");
                   scanf("%s",p);
                   postfix(sp,p,ans);
                   printf("Enter details for evaluation\n");
                   post_eva(sp,ans,1);
                   break;
            case 2:printf("enter the expression\n");
                   scanf("%s",p);
                   prefix(sp,p,a);
                   printf("Enter details for evaluation\n");
                   post_eva(sp,a,2);
                   break;
            case 3:exit(0);
        }
    }
}