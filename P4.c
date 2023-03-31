#include<stdio.h>
#include<stdlib.h>

int size=0;

typedef struct node
{
    struct node* next;
    struct node* prev;
    int data;
}node;

void display(node* head)
{
    if(size==0) 
    {
        printf("Empty DLL\n"); return;
    }
    node* temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

node* deleteByKey(node* head, int k){
    node* temp= head;
    if(temp==NULL) 
    {
        printf("LL Empty. Deletion not possible\n");
        return NULL;
    }
  do
    {
        if(temp->data==k)
        {
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            printf("Element %d deleted\n", temp->data);
            if(head==temp) head=temp->next;
            free(temp);
            size--;
            if(size==0) head=NULL;
            display(head);
            return head;
        }
        temp=temp->next;
    } while(temp!=head);
    printf("Element %d not found\n", k);
    return head;
    
}

void searchByPos(node* head, int pos){

    node* temp= head;
    if(temp==NULL) {
        printf("LL Empty\n");
        return;
    }
    int i=0;
    if(pos>size && pos<1){
         printf("Invalid position. Size is %d and position is %d\n",size,pos); return;
    }
    do
    {
        i++;
        if(pos==i){
            printf("Element %d found at position %d\n", temp->data, pos);
            display(head);
            return;
        }
        temp=temp->next;
    }while(temp!=head);
}

node* insertByOrder(node* head, int data){
       node* ptr=(node *)malloc(sizeof(node));
       ptr->data=data;

       printf("Before Insertion: \n");
    display(head);

       if(head==NULL)
       {
        ptr->next=ptr;
        ptr->prev=ptr;
        head=ptr;
       }

    if(head!=NULL)
    {
       node* tail= head->prev;
       node->next=tail->next;
       node->prev=tail;
       tail->next=ptr;
       head->prev=ptr;
    }
       
       size++;

    node* temp=head;
    node* temp2=NULL;
    
    do{
        temp2= temp->next;
        
       do{
            if(temp2->data<temp->data){
                int c= temp2->data;
                temp2->data=temp->data;
                temp->data=c;
            }
            temp2=temp2->next;
        } while(temp2!=head);
        temp=temp->next;
    }while(temp->next!=head);
    printf("After insertion: \n");
    display(head);
       return head;
}


void main()
{
    int ch,k,pos;
    node* head=NULL;
    while(1)
    {

printf("0.Exit\n1.Insert By Order\n2.Delete By Key\n3.Search By Position\n");
        printf("\n-----\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 0: exit(0);

            case 1:
            printf("Enter element to be inserted by order \n");
            scanf("%d",&k);
            head=insertByOrder(head, k);
            break;

            case 2:
            printf("Enter key to be deleted\n");
            scanf("%d",&k);
            head=deleteByKey(head, k);
            break;

            case 3:
            printf("Enter element to search\n");
            scanf("%d",&k);
            searchByPos(head, k);
            break;

            default:
            printf("Invalid character\n");
        }
    }
}