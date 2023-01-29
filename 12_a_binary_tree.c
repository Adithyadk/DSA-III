#include <stdio.h>
#include <stdlib.h>
struct root
{
    int data;
    struct root *llink;
    struct root *rlink;
};
void ord(struct root *r, int ch)
{
    if (r == NULL)
        return;
    if (r->rlink == NULL && r->llink == NULL)
    {
        printf("%d\t", r->data);
        return;
    }
    switch (ch)
    {
    case 1: ord(r->llink, 1);
            printf("%d\t", r->data);
            ord(r->rlink, 1);
            break;
    case 2: printf("%d\t", r->data);
            ord(r->llink, 2);
            ord(r->rlink, 2);
            break;
    case 3: ord(r->llink, 3);
            ord(r->rlink, 3);
            printf("%d\t", r->data);
            break;
    }
}
void insert(struct root *r, int k)
{
    if (k < r->data && r->llink == NULL)
    {
        struct root *t = malloc(sizeof(struct root));
        t->data = k;
        t->llink = NULL;
        t->rlink = NULL;
        r->llink = t;
        return;
    }
    if (k > r->data && r->rlink == NULL)
    {
        struct root *t = malloc(sizeof(struct root));
        t->data = k;
        t->llink = NULL;
        t->rlink = NULL;
        r->rlink = t;
        return;
    }
    if (k < r->data)
            insert(r->llink, k);
    if (k > r->data)
            insert(r->rlink, k);
        
}

void main()
{
    int i, k, ch;
    struct root *r = malloc(sizeof(struct root));
    printf("enter the value of root node : ");
    scanf("%d", &r->data);
    while (1)
    {
        printf("1.Build Tree\n2.Inorder Traversal\n3.Preorder Trarversal\n4.Postorder Traversal\n5.Exit\n");
        printf("Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: printf("Enter element to insert : ");
                scanf("%d", &k);
                insert(r, k);
                break;
        case 2: printf("Inorder is\n");
                ord(r, 1);
                printf("\n");
                break;
        case 3: printf("Preorder is\n");
                ord(r, 2);
                printf("\n");
                break;
        case 4: printf("Postorder is\n");
                ord(r, 3);
                printf("\n");
                break;
        case 5: exit(0);
        default:printf("Invalid Choice !!");
        }
    }
}