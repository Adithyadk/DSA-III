#include<stdio.h>
#include<stdlib.h>
int n=0;

typedef struct node
{
    int data;
    struct node *next;
} node;
node* addToEmpty(int data)
{
        node*temp=malloc(sizeof(node));
        if(temp==NULL)
        {
                printf("Memory Insufficient");
                exit(0);
        }
        temp->data=data;
        temp->next=temp;
        return temp;
}
node* insertRear(node *tail,int data)
{
        node* temp=malloc(sizeof(node));
        temp->data=data;
        temp->next=tail->next;
        tail->next=temp;
        tail=tail->next;
        return tail;
}
node* createNodeList(node* tail)
{       
        int i,data;
        printf("Enter the data for node 1:");
        scanf("%d",&data);
        tail = addToEmpty(data);
        for(i=2;i<=n;i++)
        {
                printf("enter the data for node %d:",i);
                scanf("%d",&data);
                tail=insertRear(tail,data);
        }
        return tail;
}
void display(node* tail)
{    
        node *p=tail->next;
        do{
                printf("%d\t",p->data);
                p=p->next;
        }while(p!=tail->next);
} 
node* insertFront(node *tail,int data)
{
        node* temp=malloc(sizeof(node));
        temp->data=data;
        temp->next=tail->next;
        tail->next=temp;
        return tail;
}
node* insertAfterPos(node *tail,int pos,int data)
{

        node*p=tail->next;
        node *temp=malloc(sizeof(node));
        temp->data=data;
        temp->next=NULL;
        while(pos>1)
        {
                p=p->next;
                pos--;
        }
        temp->next=p->next;
        p->next=temp;
        if(p==tail)
        {
                tail=tail->next;
        }
        return tail;
}
node* deleteFirst(node* tail)
{
        if(tail==NULL)
        return tail;
        node *p=tail->next;
        if(tail->next==tail)
        {
                free(tail);
                tail=NULL;
                return tail;
        }
        tail->next=p->next;
        free(p);
        p=NULL;
        return tail;
}
node* deleteLast(node* tail)
{
        if(tail==NULL)
        return tail;
        node *p=tail->next;
        if(tail->next==tail)
        {
                free(tail);
                tail=NULL;
                return tail;
        }
        while(p->next!=tail)
           p=p->next;
        p->next=tail->next;
        free(tail);
        tail=p;
        return tail;
}
node* deletePos(node* tail,int pos)
{       if(pos==n)
        {
                tail=deleteLast(tail);
        }
        else if(pos==1)
        {
                tail=deleteFirst(tail);
        }
        else
        {
        node *p =tail->next;
        while(pos>2)
        {
                p = p->next;
                pos--;
        } 
        node *p2 = p->next;
        p->next=p2->next;
        free(p2);
        p2=NULL;
        }
        return tail;
}
void search(node* tail)
{
        int key,flag=0,i=0;
        printf("Enter the Key element to be searched\n");
        scanf("%d",&key);
        node *p=tail->next;
        do{
                if(key==p->data)
                {
                        flag=1;
                        break;
                }
                p=p->next;
                i++;
        }while(p!=tail->next);     
        if(flag ==1)
        printf("Element %d found at pos :%d\n",key,i+1);

        else
        printf("Key  element (%d) not found\n",key);
}
node *deleteKey(node *tail)
{
    int key,f=0,i=1;
    printf("Enter the key to be Deleted\n");
    scanf("%d",&key);
    node *temp = tail->next;
    do
    {
        if (temp->data == key)
        {
            tail = deletePos(tail,i);
            return tail;
        }
        temp = temp->next;
        i++;
    } while (temp != tail->next);

    if (temp == tail->next)
    {
        printf("Key not found in the list\n");
        return tail;
    }
}
node* sort(node *tail) 
{  
node *current =tail->next, *index = NULL;  
int temp,k,count=0;  
if(tail == NULL) {  
printf("List is empty");  
}  
else {  
do{  
index = current->next;  
while(index != tail->next) 
{    
if(current->data > index->data) {  
temp =current->data;  
current->data= index->data;  
index->data = temp;  
}  
index= index->next;  
}  
current =current->next;  
}while(current->next != tail->next);   
} 
display(tail); 
        printf("Enter element to insert :");
        scanf("%d",&k);
        node *t=tail->next;
        do{
                printf("%d\t",t->data);
                count++;
                printf("count : %d\n",count);
                t=t->next;
        }while(t->data < k && t!=tail->next);
        printf("FINAL : %d\n",count);
        if(count==0)
                tail = insertFront(tail,k);
        else
                tail = insertAfterPos(tail,count,k);
        display(tail);
}  
void reverse(struct node *tail) 
{
    node* current,*prev,*nextN;  
    current=tail->next; 
    nextN=current->next;
    while(current !=tail)
    {
        prev=current;
        current=nextN;
        nextN=current->next;
        current->next=prev;
    }
    nextN->next=tail;
    tail=nextN;
    display(tail);
} 
void copy(node *tail)
{
    node *node1,*node2,*temp,*newhead;
    node2=tail;
    temp=tail;
    node1=(node*)malloc(sizeof(node));
    node1->next=NULL;
    node1->data=temp->data;
    node1->next=temp->next;
    newhead=node1;
    while(temp->next!=tail)
    {
        node1=(node*)malloc(sizeof(node));
        node1->data=temp->data;
        node1->next=temp->next;
        temp=temp->next;
    }
    temp->next=newhead;
    display(newhead);
}

void main()
{
    node *tail=NULL;
    int ch,data,pos;
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    if(n==0)
    { printf("List size Empty\n");
      exit(0);
    }    
    while (1)
    {
        printf("\n1.Read\n2.Display\n3.Insert_front\n4.Insert_rear\n5.Insert_pos\n6.Delete_first\n7.Delete_last\n8.Delete_pos\n9.Search\n10.Delete_By_Value\n11.Sort\n12.Reverse\n13.Copy_CSLL\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: tail = createNodeList(tail);
                break;
        case 2: display(tail);
                break;
        case 3: printf("Enter data\n");
                scanf("%d", &data);
                tail = insertFront(tail,data);
                display(tail);
                break;
        case 4: printf("Enter data\n");
                scanf("%d", &data);
                tail = insertRear(tail,data);
                display(tail);
                break;
        case 5: printf("Enter data\n");
                scanf("%d", &data);
                printf("Enter the position after which inserted \n");
                scanf("%d",&pos);
                tail = insertAfterPos(tail,pos,data);
                display(tail);
                break;
        case 6: tail = deleteFirst(tail);
                display(tail);
                break;
        case 7: tail=deleteLast(tail);
                display(tail);
                break;
        case 8: printf("Enter position\n");
                scanf("%d", &pos);
                tail = deletePos(tail, pos);
                display(tail);
                break;
        case 9: search(tail);
                break;
        case 10: tail=deleteKey(tail);
                 display(tail);
                 break;
        case 11: sort(tail);
                 break;
        case 12: reverse(tail);
                 break;
        case 13: printf("Copy Of the Linked list :\n");
                 copy(tail);
                 break;
        default:printf("END"); 
                exit (0);
        }
    }
}