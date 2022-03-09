#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next=NULL;
};

node*insertionAtHead(node* head, node *ptr)
{
    if(head==NULL)
    {
        ptr->next=ptr;
        return ptr;
    }
    else
    {
    node*p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    ptr->next=head;
    p->next=ptr;
    return ptr;
    }
}

void printLL(node* head)
{
    cout<<"data in CLL : ";
    if(head)
    {
        node* p=head;
        cout<<p->data<<" ";
        p=p->next;
        while(p!=head)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
}

node *deletionAtHead(node *head)
{
    if(head==head->next)
    {
        delete(head);
        return NULL;
    }
    else
    {
        node*p=head->next;
        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=head->next;
        delete(head);
        head=p->next;
        return head;
    }
}

int posModulo(node *head, int pos)
{
    node*p=head;
    int count =1;
    p=p->next;
    while(p!=head)
    {
        count++;
        p=p->next;
    }
    cout<<"size of linked linst: ";
    cout<<"count= "<<count<<endl;
    pos=pos%(count);
    if(pos==0)
    {
        pos=count;
    }
    return pos;
}

node *deletionAtAnyPosition(node *head,int pos)
{
    node *pre=head;
    node *p=head->next;
    int currentP=2;
    while(currentP!=pos)
    {
        pre=p;
        p=p->next;
        currentP++;
    }
    pre->next=p->next;
    delete(p);
    return head;
}

int main()
{
    int newElement = 1;
    node*head=NULL;
    while(newElement==1)
    {
        int d;
        cout<<"enter data: \n";
        cin>>d;
        node* ptr = new node();
        ptr -> data = d;
        head = insertionAtHead(head,ptr);
        cout<<"to insert more data press 1"<<endl;
        cin>>newElement;
    }
    cout<<"data after insertion"<<endl;
    printLL(head);

    newElement = 1;
    while(newElement==1)
    {
       int type;
       cout<<"\n 1 for deletion at head \n 2 for deletion at any other position"<<endl;
       cin>>type;
    switch(type)
    {
        case 1:
        if(!head)
        {
            cout<<"empty linked list"<<endl;
        }
        else
        {
            head=deletionAtHead(head);
        }
        break;
        case 2:
        int pos;
        cout<<"enter the position of the element to be deleted"<<endl;
        cin>>pos;
        pos=posModulo(head,pos);
        if(pos==1)
        {
            head=deletionAtHead(head);
        }
        else
        {
            head=deletionAtAnyPosition(head,pos);
        }
        break;
        default:
        cout<<"entered choice is incorrect"<<endl;
        break;
    }
    printLL(head);
    cout<<"\n\nTo delete more data press 1"<<endl;
    cin>>newElement;
   }
   printLL(head);
}