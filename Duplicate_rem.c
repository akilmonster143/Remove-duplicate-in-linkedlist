#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *link;
    long long int info;
}*start=NULL;

void addatbeg(int data)
{
    struct node *temp;
    temp=(struct node*)(malloc(sizeof(struct node)));
    temp->info=data;
    temp->link=start;
    start=temp;
}

void addatgiv(int data)
{
    struct node *current,*temp;
    temp=(struct node*)(malloc(sizeof(struct node)));
    current=start;
    while(current->link->info<data)
    {
        current=current->link;
    }
    temp->link=current->link;
    current->link=temp;
    temp->info=data;
}

void display()
{
    struct node *current;
    current=start;
    while(current!=NULL)
    {
        printf("%d ",current->info);
        current=current->link;
    }
    printf("\n");
}

void del(int data)
{
    struct node *ptr,*temp;
    ptr=start;
    if(ptr->info==data)
    {
        temp=ptr;
        start=start->link;
        free(temp);
        return;
    }
    while(ptr->link!=NULL)
    {
        if(ptr->link->info==data)
        {
            temp=ptr->link;
            ptr->link=ptr->link->link;
            free(temp);
            return;
        }
        ptr=ptr->link;
    }
    if(ptr->info==data)
    {
        temp=ptr->link;
        ptr->link=NULL;
        free(temp);
        return;
    }
}

void check()
{
    struct node *ptr,*next;
    int k;
    ptr=start;
    while(ptr->link!=NULL)
    {
        next=ptr->link;
        if(ptr->info==ptr->link->info)
        {
            k=ptr->info;
            del(k);
        }
        ptr=next;
    }
}

int main()
{
   int n,x;
   printf("Enter number of elements\n");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       scanf("%d",&x);
       if(start==NULL)
       addatbeg(x);
       else if(start->info>=x)
       addatbeg(x);
       else if(start->info<x)
       addatgiv(x);
   }
   display(); 
   
   check();

   display();
   return 0;
}
