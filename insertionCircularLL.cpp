#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next=NULL;
};
void printLL(node* head)
{
    cout<<"data in CLL : ";
    if(head)
    {
        node* ptr=head;
        cout<<ptr->data<<" ";
        ptr=ptr->next;
        while(ptr!=head)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
}
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
    pos=pos%(count+1);
    if(pos==0)
    {
        pos=count+1;
    }
    return pos;
}
node * insertionAtAnyPosition(node*head,node*ptr,int pos)
{
    node*p=head;
    int count=1;
        while(count!=pos-1)
    {
        p=p->next;
        count++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
int main()
{
    int nextElement = 1;
    node* head = NULL;
    
    while(nextElement==1)
    {
        int d;
        cout<<"enter data: \n";
        cin>>d;
        node* ptr = new node();
        ptr -> data = d;

    int type;
    cout<< " \n 1 for insertion at start. \n 2 for insertion at any point"<<endl;
    cin>>type;
    switch(type)
    {
        case 1:
        head=insertionAtHead(head,ptr);
        break;
        case 2:
        if(!head)
        {
            head=ptr;
        }
        else 
        {
            int pos;
            cout<<"\nenter the desired position to insert the element"<<endl;
            cin>>pos;
            cout<<"pos= "<<pos<<endl;
            pos= posModulo(head,pos);
            cout<<"mod pos = "<<pos<<endl;
            if(pos==1)
            {
                head=insertionAtHead(head,ptr);
            }
            else
            {
                head=insertionAtAnyPosition(head,ptr,pos);
            }
        }
        break;
        default:
         cout<<"choice entered is incorrect"<<endl;
         break;
    }
    printLL(head);
    cout<<"\n\nTo enter more data press 1"<<endl;
    cin>>nextElement;
    }
    printLL(head);
}