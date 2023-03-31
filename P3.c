#include<stdio.h>
#include<stdlib.h>

int size=0;

typedef struct node
{
    int data;
    struct node* next;
}node;

void display(node* tail)
{
    if(size==0 || tail==NULL)
    {
        printf("Linked List empty\n");
        return;
    }
    
    node* temp=tail->next;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");

}


void searchByKey(node* tail, int k)
{

    if(tail==NULL) 
    {
        printf("LL empty\n"); return;
    }
    node* head=tail->next;
    node* temp=head;
   do{
        if(temp->data==k) 
        {
            printf("Element %d found!\n",k); return;
        }
        temp=temp->next;
    } while(temp!=head);
    printf("Element %d not found\n", k);
}

node* deleteByPos(node* tail, int pos)
{
     if(tail==NULL) 
    {
        printf("LL empty\n"); return NULL;
    }
     if(pos<1 || pos>size) 
    {
        printf("Invalid position\n"); return tail;
    }
    node* head=tail->next;
    node* temp=head;
    if(pos==size)
    {
        while(temp->next!=tail) 
            temp=temp->next;
        
        temp->next=tail->next;
        printf("Element %d found at tail\n", tail->data); 
        free(tail);
        size--;
        if(size==0) temp=NULL; 
        display(temp);
        return temp;
    }
    temp=head;
    node*prev=tail;
    int i=0;
    do{
        i++;
        if(i==pos) 
        {
            printf("Element %d found! at given position %d\n", temp->data, pos); 
            prev->next=temp->next;
            free(temp);
            size--;
            printf("SIZE %d\n", size);
            display(tail);
            return tail;
        }
        prev=temp;
        temp=temp->next;
    }while(temp!=head);
    printf("Element %d not found\n", pos);
    return tail;
}

node* insertByOrder(node* tail, int data)
{
       node* ptr=(node *)malloc(sizeof(node));
       ptr->data=data;
       ptr->next=NULL;
    if(tail==NULL) 
    {
       tail=ptr;
       ptr->next=tail;
       size++;
       display(tail);
         return tail;
    }
    
    node* head=tail->next;
    //Insertion
    tail->next=ptr;
    ptr->next=head;
    tail=ptr;
    size++;

    printf("Before Insertion: \n");
    display(tail);
    
    //Ordering
    node* temp=head;
    node* temp2=NULL;
    do
    {
        temp2= temp->next;
        
        do{
            if(temp2->data<temp->data){
                int c= temp2->data;
                temp2->data=temp->data;
                temp->data=c;
            }
            temp2=temp2->next;
        }while(temp2!=head);
        temp=temp->next;
    }while(temp->next!=head);
    printf("After insertion: \n");
    display(tail);
       return tail;
}

void main()
{
    int ch,k,pos;
    node* tail=NULL;
    node* h2=NULL;
    while(1)
    {
        printf("0.Exit\n1.Insert By Order\n2.Delete By Position\n3.Search By Key\n");
        printf("\n-----\nEnter you choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: 
            exit(0);

            case 1:
            printf("Enter element to be inserted by order ");
            scanf("%d",&k);
            tail=insertByOrder(tail, k);
            break;

            case 2:
            printf("Enter pos to delete\n");
            scanf("%d",&pos);
            tail=deleteByPos(tail, pos);
            break;

            case 3:
            printf("Enter element to search\n");
            scanf("%d",&k);
            searchByKey(tail, k);
            break;


            default: printf("Invalid choice\n");
        }
    }
}