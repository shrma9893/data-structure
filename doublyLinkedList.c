#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};

struct node* head=NULL;

struct node* getNewNode(int data)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->prev=NULL;
    new->next=NULL;
    new->data=data;
    return new;
}

void insertAtHead(int data)
{
    struct node* new=getNewNode(data);

    if(head==NULL)
    {
        head=new;
        return;
    }
    head->prev=new;
    new->next=head;
    head=new;
}
void insertAtTail(int data)
{
    struct node* new=getNewNode(data);
    if(head==NULL)
    {
        head=new;
        return;
    }
    struct node *t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=new;
    new->prev=t;
}

void print()
{
    struct node *t=head;
    printf("FORWARD:");
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

void reversePrint()
{
    struct node *t=head;
    if(!t) return;
    while(t->next)
        t=t->next;
    printf("REVERSE:");
    while(t)
    {
        printf("%d ",t->data);
        t=t->prev;
    }
    printf("\n");
}

void main()
{
    insertAtHead(1);print();reversePrint();
    insertAtHead(2);print();reversePrint();
    insertAtHead(3);print();reversePrint();
    insertAtHead(4);print();reversePrint();
    insertAtTail(1);print();reversePrint();
    insertAtTail(2);print();reversePrint();
    insertAtTail(3);print();reversePrint();
    insertAtTail(4);print();reversePrint();
}
