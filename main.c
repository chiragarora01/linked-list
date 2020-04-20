#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct noded
{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head=NULL;

int main()
{
    insert_front();
    display();
    delete_front();
    display();
    return 0;
}

void insert_front()
{
    struct node* temp;
    int num;
    printf("\nenter the data ");
    scanf("%d",&num);
     temp=(struct node*)malloc(sizeof(struct node));
        temp->data=num;

    if (head==NULL)
    {
        temp->next=NULL;
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void insert_between()
{
    struct node* temp,*p;
    int num,pos;
    printf("\nenter the position ");
    scanf("%d",&pos);
    printf("\nenter the data ");
    scanf("%d",&num);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    p=head;
    if (head==NULL)
    {
        head=temp;
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
void insert_end()
{
    struct node* temp,*p;
    int num;
    printf("\nenter the data ");
    scanf("%d",&num);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    if (head==NULL)
    {
        head=temp;
    }
    else
    {
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->next=NULL;
        temp=head;
    }

}
void delete_front()
{
    struct node *temp,*p;
    if(head->next==NULL)
    {
        free(head);
    }
    else
    {
        temp=head;
        free(temp);
        p->next=head;
    }
}
void delete_between()
{
    struct node *temp,*p;
    int pos;
    p=head;
    printf("\nenter the position ");
    scanf("%d",&pos);

    if(p->next==NULL)
    {
        free(head);
    }
    else
    {
        for(int i=0;i<pos;i++)
        {
            p=p->next;
        }
        p->next=temp;
        p->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
}
void delete_end()
{
    struct node *temp,*p;
    p=head;
    if(p->next==NULL)
    {
        free(head);
    }
    else
    {
        while(p->next->next!=NULL)
        {
            p=p->next;
        }
        free(p->next);
        p->next=NULL;
    }
}
void double_front()
{

}
void display()
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d-->",p->data);
        p=p->next;
    }
}
