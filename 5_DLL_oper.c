#include<stdio.h>
#include<stdlib.h>
int n=0;

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node* addToEmpty(node* head,int data)
{ 
    node* temp= malloc(sizeof(node));
    temp->prev = NULL; 
    temp->data = data;      
    temp->next = NULL; 
    head = temp;
    return head;
}

void insertRear(node* head,int data)
{
    node* temp,*ptr;
    temp= malloc(sizeof(node));
    temp->prev = NULL; 
    temp->data = data;      
    temp->next = NULL; 
    ptr = head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
}

node* createNodeList()
{
    node* head= malloc(sizeof(node));
    if(head == NULL) 
    {
        printf(" Memory can not be allocated.");
        exit(0);
    }
    int data,i;
    printf(" Input data for node 1 : ");
    scanf("%d", &data);
    head=addToEmpty(head,data);

    for(i=2;i<=n;i++)
    {
        printf(" Input data for node %d :",i);
        scanf("%d", &data);
        insertRear(head,data);
    }
    return head;
}

void display(node *head)
{
    node *ptr = head;
    printf("Linked list is--> ");
    while (ptr!= NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
}

node* insertFront(node*head,int data)
{
    node* temp=malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
node* insertPos(node*head,int pos,int data)
{
    node* temp=NULL;
    node* ptr=head;
    node* ptr2=NULL;
    temp=addToEmpty(temp,data);
    if(pos == 1)
    {
        head=insertFront(head,data);
        return head;
    }
    if (pos==n+1)
    {
     insertRear(head,data);
     return head;
    }
    while (pos != 2)
    {
        ptr=ptr->next;
        pos--;
    }
    ptr2=ptr->next;
    ptr->next=temp;
    ptr2->prev=temp;
    temp->next=ptr2;
    temp->prev=ptr;
   return head;
}
node* deleteFirst(node*head)
{
    head=head->next;
    free(head->prev);
    head->prev=NULL;
}

void deleteLast(node*head)
{
    node* temp2=NULL;
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;
}

node *deletePos(node *head,int pos)
{
    node* temp=head;
    node* temp2=NULL;
    if(pos==1)
    {
        head=deleteFirst(head);
        return head;
    }
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL)
     deleteLast(head);
    else
    {
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head; 
}

void search(node *head)
{
    node* ptr=head;
    int key,flag=0,i=0;
    printf("Enter the Key element to be searched\n");
    scanf("%d",&key);
    while(ptr != NULL)
    {
        if(key == ptr->data)
        {
            flag=1;
            break;
        }
        ptr = ptr->next;
        i++;
    }
    if(flag ==1)
    printf("Element %d found at pos :%d\n",key,i+1);

    else
    printf("Key  element (%d) not found\n",key);
}

node *deleteKey(node *head)
{
    int key,f,i=0;
    node *ptr=head;
    printf("Enter the key to be Deleted\n");
    scanf("%d",&key);
    while(ptr != NULL)
    {
        if(key == ptr->data)
        {
            f=1;
            break;
        }
        ptr = ptr->next;
        i++;
    }  
    if(f==1 && i>0)
    head = deletePos(head,i+1);
    else
    printf("%d not present in DLL\n",key);
    return head;
}

void sort(node *head ) 
{  
        node *ptr =NULL;
        node*index = NULL;  
        int c,k,count=1;      
         {  
            for(ptr= head; ptr!= NULL;ptr=ptr->next) 
            {               
                for(index=ptr->next;index != NULL;index=index->next)
                {  
                    if(ptr->data > index->data) 
                    {  
                        c = ptr->data;  
                        ptr->data = index->data;  
                        index->data = c;  
                    }  
                }  
            }      
        } 
        display(head);
        printf("Enter element to insert :");
        scanf("%d",&k);
        node *t=head;
        while(t->data <k && t!=NULL)
        {
            count++;
            //printf("count : %d\n",count);
            if(t->next ==NULL)
            {
                break;
            }
            t = t->next;
        }
        //printf("FINAL : %d\n",count);
        head = insertPos(head,count,k);
        display(head);
}  
node *reverse(node *head)
{  
  node* ptr1=head;
  node* ptr2=ptr1->next;
  ptr1->next=NULL;
  ptr1->prev=NULL;
  while(ptr2!=NULL)
  {
    ptr2->prev=ptr2->next;
    ptr2->next=ptr1;
    ptr1=ptr2;
    ptr2=ptr2->prev;
  }
  head=ptr1;
  display(head);
  return head;
}

node *copy(node *head)
{
    node *ptr=head;
    if (ptr == NULL)
    {
        return NULL;
    }
    else
    {
        node* cpy=malloc(sizeof(node));
        cpy->data = ptr->data;
        cpy->next = copy(ptr->next);
        return cpy;    
    }
    
}

void main()
{
    node *ptr,*head=NULL;
    int ch,data,pos;
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    if(n==0)
      exit(0);    
    while (1)
    {
        printf("\n1.Read\n2.Display\n3.Insert_front\n4.Insert_rear\n5.Insert_pos\n6.Delete_first\n7.Delete_last\n8.Delete_pos\n9.Search\n10.Delete_By_Value\n11.Sort\n12.Reverse\n13.Copy_DLL\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: head = createNodeList();
                break;
        case 2: display(head);
                break;
        case 3: printf("Enter data\n");
                scanf("%d", &data);
                head = insertFront(head,data);n++;
                display(head);
                break;
        case 4: printf("Enter data\n");
                scanf("%d", &data);
                insertRear(head,data);n++;
                display(head);
                break;
        case 5: printf("Enter data\n");
                scanf("%d", &data);
                printf("Enter the position\n");
                scanf("%d",&pos);
                head = insertPos(head,pos,data);n++;
                display(head);
                break;
        case 6: head = deleteFirst(head);n--;
                display(head);
                break;
        case 7: deleteLast(head);n--;
                display(head);
                break;
        case 8: printf("Enter position\n");
                scanf("%d", &pos);
                head = deletePos(head, pos);n--;
                display(head);
                break;
        case 9: search(head);
                break;
        case 10: head=deleteKey(head);n--;
                 display(head);
                 break;
        case 11: sort(head);n++;
                 break;
        case 12: head = reverse(head);
                 break;
        case 13: ptr = copy(head);
                 printf("Copy Of the Linked list :\n");
                 display(ptr);
                 break;
        default:printf("END"); 
                exit (0);
        }
    }
}
    
