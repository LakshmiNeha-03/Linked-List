#include <iostream>
using namespace std;
struct node
{
int data;
node *next = NULL;
};

void printLL(node*head)
{
    while(head)
    {
        cout<< head->data <<" ";
        head = head->next;
    }   
}
node* insertion(node* head, node* ptr)
{
   if(!head)
       {
          ptr ->next = head;
          head = ptr;
          return head;
       }
       else
        {
         node* p = head;
         while(p->next)
          {
              p = p->next;
          }
          p->next = ptr;
          return head;   
        }
}
node* deletionAtBeforeParticularElement(node*head, int x)
{
    node*p=head;
    if(!p)
    {
        cout<<"\nlinked list is empty"<<endl;
        return p;
    }
    else if(p && p->data==x)
    {
        cout<<"\nthis is the first node"<<endl;
        return p;
    }
    else if(p && p->next && p->next->data==x)
    {
        cout<<"\nhead position is changed"<<endl;
        p = p->next;
        delete(head);
        return p;
    }
    else
    {
        node*pre=NULL;
        while(p && p->next && p->next->data!=x)
        {
            pre=p;
            p=p->next;
        }
        if(p && p->next)
        {
            pre->next=p->next;
            delete(p);
        }
        return head;
    }
}
int main()
{
    node* head = NULL;
    int nextElement=1;
    while(nextElement==1)
    {
        int d;
        cout<<"enter data: ";
        cin>>d;
        node* ptr = new node();
        ptr -> data = d;
        head = insertion(head,ptr);
        cout<<"data after insertion"<<endl;
        printLL(head);
        int x;
        cout<<"\nenter the element before which you want to delete the data"<<endl;
        cin>>x;
        head=deletionAtBeforeParticularElement(head,x);
        cout<<"\nData in linked list: ";
        printLL(head);
        cout<<"\nTo enter more data press 1 : ";
        cin>>nextElement;
    }
    cout<<"\nData in linked list: ";
    printLL(head);
}

