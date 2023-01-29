#include<stdio.h>
#include<stdlib.h>
typedef struct node{
 int data;
 struct node* prev;
 struct node* next;
}node;

node*createNode(void)
{
 node*newnode = malloc(sizeof(node));
 printf("\nEnter the data:\t"); 
 scanf("%d",&newnode->data);
 newnode->next = NULL;
 newnode->prev = NULL;
 return newnode;
}

node*createLL(node*h)
{
 int n,i;
 printf("Enter the number of Nodes:\t"); 
 scanf("%d",&n);
 h = malloc(sizeof(node));
 h->prev = h;
 h->next = h;
 h->data = 0;
 if(n == 0)
 return h;
 else
 {
 node*newnode;
 for(i=0; i<n; i++)
 { 
 printf("\nInput data for Node %d",i+1);
 newnode = createNode();
 newnode->next = h;
 newnode->prev = h->prev;
 h->prev->next = newnode;
 h->prev = newnode;
 h->data += 1;
 }
 return h;
 }
}

void display(node*h)
{
 printf("\nCurrent status of the linked list is...\n");
 printf("Number of nodes: %d\n",h->data);
 printf("\nLinked list");
 if(h->data == 0)
 {
 printf(":\tIt is empty");
 }
 else
 { printf("\n");
   node*temp = h->next;
   while(temp != h)
 {
   printf("%d\t",temp->data);
   temp = temp->next;
 }
 }
}

node*insertBeg(node*h)
{
 node* newnode;
 printf("\nFor the node to be inserted at the beginning...\n");
 newnode = createNode();
 newnode->prev = h;
 newnode->next = h->next;
 h->next->prev = newnode;
 h->next = newnode;
 h->data += 1;
 return h;
}

node* insertEnd(node*h)
{
 node*newnode;
 printf("\nFor the node to be inserted at the end:\t");
 newnode = createNode(); 
 newnode->next = h;
 newnode->prev = h->prev;
 h->prev->next = newnode;
 h->prev = newnode;
 h->data += 1;
 return h;
}

node* deleteBeg(node*h)
{
 node*temp;
 temp = h->next;
 h->next = temp->next;
 temp->next->prev = h;
 free(temp);
 if(h->data <= 0)
 h->data = 0;
 else
 h->data -=1;
 return h;
}

node* deleteEnd(node*h)
{
 if(h->data == 0)
 {
 return h;
 }
 else
 {
 node*temp;
 temp = h->prev;
 temp->prev->next = h; 
 h->prev = temp->prev;
 free(temp);
 if(h->data <= 0)
 h->data = 0;
 else
 h->data -=1;
 return h;
 }
}
node* deleteAtPosition(node*h, int p)
{
 int i;
 node*temp;
 temp = h->next;
 for(i=1; i<p; i++)
 {
 temp = temp->next;
 }
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
 free(temp);
 if(h->data <= 0)
 h->data = 0;
 else
 h->data -=1;
 
 return h;
}
node* insertAtPosition(node*h, int p)
{
 int i;
 node*temp; node*newnode;
 temp = h->next;
 for(i=1; i<p; i++)
 {
 temp = temp->next;
 }
 printf("\nFor the data to be inserted at position %d...\n",p);
 newnode = createNode();
 newnode->prev = temp->prev;
 newnode->next = temp;
 temp->prev->next = newnode;
 temp->prev = newnode;
 h->data += 1;
 return h;
}
node* deleteByKey(node*h)
{
 int key,flag = 1,i = 1;
 printf("\nEnter the key:\t"); scanf("%d",&key);
 node*temp = h->next;
 while(temp != h)
 {
 if(temp->data == key)
 {
 printf("\nElement found at position %d\n",i);
 temp->prev->next = temp->next;
 temp->next->prev = temp->prev;
 free(temp);
 h->data -= 1;
 flag = 0;
 break;
 }
 else
 {
 temp = temp->next;
 i++;
 }
 }
 if(flag == 1)
 {
 printf("\nELement absent\n");
 }
 return h;
}
void searchByKey(node*h)
{
 int key, flag = 1,i = 1;
 printf("\nEnter the key:\t"); scanf("%d",&key);
 node*temp = h->next;
 while(temp != h)
 {
 if(temp->data == key)
 {
 printf("\nElement found at position %d\n",i);
 flag = 0;
 break;
 }
 else
 {
 temp = temp->next;
 i++;
 }
 }
 if(flag == 1)
    printf("\nElement absent\n");
}
node *sort(node *h) 
{   
        int count=0,k;
        struct node*temp = h->next;
        node *ptr =NULL;
        node*index = NULL;  
        int c;        
            for(ptr= temp; ptr!= h;ptr=ptr->next) 
            {               
                for(index=ptr->next;index != h;index=index->next)
                {  
                    if(ptr->data > index->data) 
                    {  
                        c = ptr->data;  
                        ptr->data = index->data;  
                        index->data = c;  
                    }  
                }  
            }      
        display(h);
        printf("Enter element to insert :");
        scanf("%d",&k);
        node *t = h->next;
        while(t != h && k > t->data)
        {
        t = t->next;
        count++;
        }
        h = insertAtPosition(h,count+1);
        display(h);
        return h;
}

node* reverseList(node*h)
{
 int i;
 node*left = h->prev;
 node*right = h->next;
 int temp;
 
 for(i=0; i<h->data/2; i++)
 {
 temp = right->data;
 right->data = left->data;
 left->data = temp;
 left = left->prev;
 right = right->next;
 }
 return h;
}
node* copyLL(node*h,node*h2)
{
 h2 = malloc(sizeof(node));
 h2->prev = h2;
 h2->next = h2;
 h2->data = 0;
 node*temp = h; node*current = h2;
 
 do{
 temp = temp->next;
 current->next = (node*)malloc(sizeof(node));
 current->next->prev = current;
 current = current->next;
 current->next = h2;
 h2->prev = current;
 current->data = temp->data;
 }while(temp->next != h);
 h2->data = h->data;
 return h2;
}

void main()
{
 node* head = NULL, *ptr = NULL;
 int ch,pos;
 while(1)
 {
 printf("\n1.Read\n2.Display\n3.Insert_front\n4.Insert_rear\n5.Insert_pos\n6.Delete_first\n7.Delete_last\n8.Delete_pos\n9.Search\n10.Delete_By_Value\n11.Sort\n12.Reverse\n13.Copy\n");
 printf("Enter your choice:\t"); 
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:head = createLL(head); 
        display(head);
        break;
 
 case 2:display(head);
        break;
 
 case 3:head = insertBeg(head); 
        display(head); 
        break;
 
 case 4: head = insertEnd(head);
         display(head);
         break;
 
 case 5: printf("\nEnter the position:\t"); 
         scanf("%d",&pos); 
         if(pos<=0 || pos>head->data+1)
         {
          printf("\nInvalid Position...\n");
          break;
         } 
         head = insertAtPosition(head,pos);
         display(head);
         break;
 
 case 6: head = deleteBeg(head);
         display(head); 
         break;
 
 case 7: head = deleteEnd(head);
         display(head); 
         break;
 case 8: printf("\nEnter the position:\t"); 
         scanf("%d",&pos);
          if(pos<=0 || pos>head->data)
          {
             printf("\nInvalid Position...\n"); 
             break;
          }
          head = deleteAtPosition(head,pos); 
          display(head); 
          break;

 case 9: searchByKey(head); 
         break;

 case 10:head = deleteByKey(head);
         display(head); 
         break;
 
 case 11:sort(head);
         break;

 case 12:head = reverseList(head);
         display(head); 
         break;

 case 13: ptr = copyLL(head,ptr);
          printf("Copy of the Header CDLL");
          display(ptr); 
          break;

 default:printf("END"); 
         exit(0);
 }
 }
}