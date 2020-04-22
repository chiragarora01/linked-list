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
struct noded* headed=NULL;

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
    struct node *temp;
    if(head->next==NULL)
    {
        free(head);
    }
    else
    {
        temp=head;
        free(temp);
        head=temp->next;
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
        temp=p->next;
        p->next=temp->next;
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

    }
}
void double_front_insert()
{
    struct noded* temp;
    int num;
    printf("\nenter the data ");
    scanf("%d",&num);
    temp=(struct noded*)malloc(sizeof(struct noded));
        temp->data=num;

    if (headed==NULL)
    {
        temp->next=NULL;
        temp->prev=NULL;
        headed=temp;
    }
    else
    {
        temp->next=headed;
        temp->prev=NULL;
        headed->prev=temp;
        headed=temp;
    }
}
void double_end_insert()
{
    struct noded* temp,*p;
    int num;
    printf("\nenter the data ");
    scanf("%d",&num);
    temp=(struct noded*)malloc(sizeof(struct noded));
        temp->data=num;

    if (headed==NULL)
    {
        temp->next=NULL;
        temp->prev=NULL;
        headed=temp;
    }
    else
    {
        p=headed;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
        temp->next=NULL;

    }
}
void double_mid_insert()
{
    struct noded* temp,*p;
    int num,pos;
    printf("\nenter the position ");
    scanf("%d",&pos);
    printf("\nenter the data ");
    scanf("%d",&num);
    temp=(struct noded*)malloc(sizeof(struct noded));
    temp->data=num;
    p=headed;
    if (headed==NULL)
    {
        headed=temp;
    }
    else
    {
         for(int i=0;i<pos;i++)
        {
            p=p->next;
        }
        temp->next=p->next;
        temp->prev=p;
        p->next=temp;
        temp->next->prev=temp;
    }
}
void display()
{
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
void double_display()
{
    struct node *p;
    p=headed;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
void circular_insert_front()
{
    struct node* temp,*p;
    int num;
    printf("\nenter the data ");
    scanf("%d",&num);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;

    if (head==NULL)
    {
        temp=temp->next;
        head=temp;
    }
    else
    {
        p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        temp=p->next;
        head=temp->next;
    }
}
void circular_insert_mid()
{
    struct node *temp,*p;
    int i,num,pos;
    printf("\nenter the data");
    scanf("%d",&num);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    if(head=NULL)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        p=head;
        while( i<pos)
        {
            p=p->next;
            i++;
        }
        temp->next=p->next;
        p->next=temp;

    }


}
void circular_insert_end()
{
    struct node* temp,*p;
    int num;
    printf("\nenter the data ");
    scanf("%d",&num);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;

    if (head==NULL)
    {
        temp->next=temp;
        head=temp;
    }
    else
    {
        p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        head=temp->next;
        p->next=temp;
    }
}
void circular_delete_front()
{
    struct node *p;
    p=head;
    if(head->next=head)
        free(head);
    else
    {
        while(p->next!=head)
        {
            p=p->next;
        }
    }
}
