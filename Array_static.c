#include <stdio.h>
#include <stdlib.h>
int n;
void read(int *arr)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
}
void display(int *arr)
{
    int i;
    printf("%d",*(arr+1));
    /*for (i = 0; i < n; i++)
    {
        printf(" %d ", *(arr + i));
    }*/
}
void search(int *arr, int key)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (key == *(arr + i))
        {
            printf(" %d found at %d ", key, i + 1);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf(" element not found ");
    }
}
void insert_ele(int *arr,int value, int pos)
{

    int i;
    if (pos >= 0 && pos <= n - 1)
    {
        for (i = n - 1; i >= pos; i--)
        {
            *(arr + i + 1) = *(arr + i);
        }

        *(arr + pos) = value;
        (n)++;
        display(arr);
    }
    else
        printf("Inavlid Position\n");
}
void delete (int *arr,int pos)
{
    int i;
    if (pos >= 0 && pos <= n - 1)
    {
        for (i = pos; i <= n - 1; i++)
        {
            *(arr + i) = *(arr + i + 1);
        }
        (n)--;
        display(arr);
    }
    else
    {
        printf("Inavlid Position\n");
    }
}
void delete_vl(int *arr, int value)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (*(arr + i) == value)
        {
            flag = 1;
            for (int j = i; j <= n - 1; j++)
            {
                *(arr + j) = *(arr + j + 1);
            }
            (n)--;
            display(arr);
            return;
        }
    }
    if (flag == 0)
    {
        printf("value not found");
    }
}

void main()
{
    int ch, key, pos, value, arr[10];
    while (1)
    {
        printf(" \n1.Read \n2.Display\n3.Search\n4.Insert\n5.Delete\n6.DeleteByVal\n7.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the size of the array\n");
            scanf("%d", &n);
            printf("enter the elements\n");
            read(arr);
            break;
        case 2:
            printf("the elements are \n");
            display(arr);
            break;
        case 3:
            printf("enter the key to searched\n ");
            scanf("%d", &key);
            search(arr, key);
            break;
        case 4:
            printf("enter the postion and value of the new key\n");
            scanf("%d %d", &pos, &value);
            pos=pos-1;
            insert_ele(arr, value, pos);
            break;
        case 5:
            printf("enter the postion to be deleted\n");
            scanf("%d", &pos);
            pos=pos-1;
            delete (arr,pos);
            break;
        case 6:
            printf("enter the value to be deleted\n");
            scanf("%d", &value);
            delete_vl(arr,value);
            break;
        case 7:
            exit(0);
        default:
            printf("entered value is wrong");
            break;
        }
    }
}