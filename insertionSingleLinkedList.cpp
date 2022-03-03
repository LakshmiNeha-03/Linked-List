# include <iostream>
using namespace std;

struct node
{
int data;
node *next = NULL;
};

void printLinkedList(node* head)
{
    while(head)
    {
        cout<< head->data <<" ";
        head = head->next;
    }   
}

node* insertionAtStart(node* head, node* ptr)
{
    ptr ->next = head;
    head = ptr;
    return head;
}

node* insertionAtLast(node* head, node* ptr)
{
   if(!head)
       {
           return insertionAtStart(head,ptr);
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

node* insertionAtParticularPosition(node*head, node* ptr,int pos)
{   
    if(pos==1)
    {
        return insertionAtStart(head,ptr);
    }

    int count=1; 
    node*p = head;
   while(count<pos-1 && p )
   {
       p=p->next;
       count++;
   }
   if(p)
   {
       ptr->next=p->next;
       p->next=ptr;
       return head;
   }
   else
   {
       cout<<"\nentered position is invalid"<<"\ninsertion at last is done"<<endl;
       return insertionAtLast( head, ptr);
   }
     
}

node* insertionAfterParticularElement(node* head, node* ptr, int key)
{
    node* p =head;
    while(p && p->data!=key)
    {
        p=p->next;
    }
    if(!p)
    {
       cout<<"\nelement is not present in linked list"<<"\n insertion at last is done.";
        return insertionAtLast(head, ptr);
    }
    else
    {
        ptr->next=p->next;
        p->next=ptr;
        return head;
    }
 }
 
node* insertionBeforeParticularElement(node* head, node* ptr, int key)
{
    node* p =head;
    if(p->data==key)
    {
        return insertionAtStart(head,ptr);
    }
    while(p && p->next->data!=key)
    {
        p=p->next;
    }
    if(!p)
    {
        cout<<"\n element is not present in linked list" << "\n insertion at last is done.";
        return insertionAtLast(head, ptr);
    }
    else
    {
        ptr->next=p->next;
        p->next=ptr;
        return head;
    }
 }

int main()
{
    int nextElement = 1;
    node* head = NULL;
    
    while(nextElement==1)
    {
        int d;
        cout<<"enter data: ";
        cin>>d;
        node* ptr = new node();
        ptr -> data = d;

    int type;
    cout<< "\n 1 for insertion at start. \n 2 for insertion at last. \n 3 for insertion at desired position. \n 4 for insertion after elements. \n5 for insertion before elements.";
    cin>>type;

        switch(type)
    {
        case 1:
               head = insertionAtStart(head,ptr);
               break;
        case 2:
              head = insertionAtLast(head, ptr);
              break;
        case 3:
            int pos;
            cout<<"\nEnter the position to insert the data: ";
            cin>>pos;
            head = insertionAtParticularPosition(head, ptr, pos);
            break;
        case 4:
            int key1;
            printLinkedList(head);
            cout<<"\nEnter the element after which you want to insert the data: ";
            cin>>key1;
            head = insertionAfterParticularElement(head, ptr, key1);
            break;
        case 5:
        int key2;
            printLinkedList(head);
            cout<<"\nEnter the element before which you want to insert the data: ";
            cin>>key2;
            head = insertionBeforeParticularElement(head, ptr, key2);
            break;
        default: 
              cout<<"\n choice is incorrect. Enter a valid choice."<<endl;
              break;
    }
    cout<<"Data in linked list: ";
    printLinkedList(head);
        cout<<"\nTo enter more data press 1 : ";
        cin>>nextElement;
    }
 cout<<"Data in linked list: ";
 printLinkedList(head);
}