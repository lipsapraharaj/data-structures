
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    X info;
    struct node<X> *next;
}*start;
 
/*
 * Class Declaration
 */
template <class X>
class single_llist
{
    public:
        void insert_begin();
        void insert_pos();
        void insert_last(); 
        void count();
        void search();
        void delete_begin;
        void delete_pos();
        void delete_end():
        void reverse();
        void display();
        void operator +(SinglyLinkedList &l); 
        single_llist()
        ~single_llist() 
        {
            start = NULL;
        }
};
 
/*
 * Main :contains menu 
 */
 int main()

{  SinglyLinkedList<int>* list_1 = new SinglyLinkedList<int>();
   SinglyLinkedList<int>* list_2 = new SinglyLinkedList<int>(); 
   int choice, nodes, element, position, i,totalNodes;
    single_llist<int> sl;
    start = NULL;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Count the number of nodes"<<endl;
        cout<<"5.Delete from beginning\n";
        cout<<"6.Delete from the end\n";
        cout<<"7.Delete from specified position\n";
        cout<<"8.Search Element"<<endl;
        cout<<"9.Reverse Linked List"<<endl;
        cout<<"10.Display Linked List "<<endl;
        cout<<"11.Concatenate (1 = 1 + 2)\n"
        cout<<"12. Concatenate (2 = 2 + 1)\n"
        cout<<"13.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"The number of nodes "<<endl;
            sl.count();
            cout<<endl;
            break;
       
        case 5:
             cout<<"Delete a node from front";
             sl.delete_begin();
             break;
        case 6:
              cout<<"Delete a node from back"; 
              sl.delete_end();
              break;
         case 7:
              cout<<"Delete a particular node: "<<endl;
              sl.delete_pos();
              break;
         case 8:
              cout<<"Search in linked list"<<endl;
              sl.search();
              break;
        
        case 9:
            cout<<"Reverse elements of Link List"<<endl;
            sl.reverse();
            cout<<endl;
            break;
           
        case 10:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 11:
            cout<<"Concatenate linked lists"<<endl;
             *list_1 + *list_2;
            cout<<endl;
            break;
         case 12:
             *list_2 + *list_1;
            cout<<endl;
            break;
            
        case 13:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
 

 /*
 *  Destructor
 */
  void single_llist<X>::~single_llist()
  
   {
    
    if (this->isEmpty())
 
   struct node<X> *ptr, *temp = head;
    
   while (temp->ptr!= NULL)
    
  {
      
   ptr = temp->ptr;
      
   delete temp;
      
   temp = ptr;
    
  }
    
   head = tail = NULL;
    
   return 0;
}


/*
 * Inserting element in beginning
 */
template<class X>
void single_llist<X>::insert_begin()
{
    X value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node<X> *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
}
 
/*
 * Inserting Node at last
 */
template<class X>
void single_llistt<X>::insert_last()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node<X> *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Element Inserted at last"<<endl;  
}
 
/*
 * Insertion of node at a given position
 */
template<class X>
void single_llist<X>::insert_pos()
{
    X value, pos, counter = 0; 
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node<X> *temp, *s, *ptr;
    temp = create_node(value);
    cout<<"Enter the postion at which node to be inserted: ";
    cin>>pos;
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        cout<<"Positon out of range"<<endl;
    }
}

 int count()
{
if(this->isEmpty())
{
cout<<"List is empty";
return -1;
}
int count=0;
struct node<X> *temp;
for(temp=head;temp!=NULL;temp=temp->ptr,count++)
return count;
}

/*
 * Deletion of Link List
 */
 template<class X>
void single_llist<X>::delete_begin()
{
        struct node<X> *ptr;
        if(ptr==NULL)
        {
                cout<<"\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                cout<<"\nThe deleted element is :"ptr->info;
               delete ptr;
        }
}
template<class X>
void single_llist<X>::delete_end()
{
        struct node<X> *temp,*ptr;
        if(start==NULL)
        {
                cout<<"\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                cout<<"\nThe deleted element is:%d\t",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                cout<<"\nThe deleted element is:"<<ptr->info;
                delete ptr;
        }
}
template<class X>
void single_llist<X>::delete_pos()
{
        X i,pos;
        struct node<X> *temp,*ptr;
        if(start==NULL)
        {
                cout<<"\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                cout<<"\nEnter the position of the node to be deleted:\t";
               
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        cout<<"\nThe deleted element is:"<<ptr->info  ;
                        delete ptr;
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++)
                        {
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        cout<<"\nPosition not Found:\n";
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        cout<<"\nThe deleted element is:"<<ptr->info;
                        delete ptr;;
                }
        }
}
 
/*
 * Searching an element
 */
template<class X>
void single_llist<X>::search()
{
    X value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct node<X> *s;
    s = start;
    while (s != NULL)
    {
        pos++;
        if (s->info == value)
        {
            flag = true;
            cout<<"Element "<<value<<" is found at position "<<pos<<endl;
        }
        s = s->next;
    }
    if (!flag)
        cout<<"Element "<<value<<" not found in the list"<<endl;  
}
 
/*
 * Reverse Link List
 */
template<class X>
void single_llist<X>::reverse()
{
    struct node<X> *prev=NULL, *temp=head, *next=NULL;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
       
    }
    while (temp!= NULL)
    {
next=temp->ptr;
temp->ptr=prev;
prev=temp;
temp=next;
}
   head=prev;
cout<<"\nList has been reversed";
     delete next,temp;
return 0;
   
}

/*
 * Display Elements of a link list
 */
template<class X>
void single_llist<X>::display()
{
    struct node<X> *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

/*
 * Concatenate 
 */

template<class X>
void SinglyLinkedList<X> :: operator +(SinglyLinkedList<X> &l)
{
    if(this->totalNodes > 0 && l.totalNodes > 0)
    {
        this->temp = tail;
        Node<X> *newNode = 0;
        l.temp = l.head;
        while(l.temp != 0)
        {
            newNode = new Node<X>(l.temp->data,0);
            this->totalNodes++;
            this->temp->next= newNode;
            this->temp = this->temp->next;
            l.temp = l.temp->next; 
        }
        this->tail = newNode;
        this->temp = l.temp = newNode = 0;
    }
}

