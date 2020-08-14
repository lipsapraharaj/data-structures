
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*start;
 
/*
 * Class Declaration
 */
class single_llist
{
    public:
        node* create_node(int);
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
        single_llist() 
        {
            start = NULL;
        }
};
 
/*
 * Main :contains menu 
 */
main()
{
    int choice, nodes, element, position, i;
    single_llist sl;
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
        cout<<"11.Exit "<<endl;
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
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
 
/*
 * Creating Node
 */
node *single_llist::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;     
        return temp;
    }
}
 
/*
 * Inserting element in beginning
 */
void single_llist::insert_begin()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *p;
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
void single_llist::insert_last()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s;
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
void single_llist::insert_pos()
{
    int value, pos, counter = 0; 
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp, *s, *ptr;
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
struct node *temp;
for(temp=hed;temp!=NULL;temp=temp->ptr,count++)
return count;
}

/*
 * Deletion of Link List
 */
 void delete_begin()
{
        struct node *ptr;
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
void delete_end()
{
        struct node *temp,*ptr;
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
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
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
void single_llist::search()
{
    int value, pos = 0;
    bool flag = false;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the value to be searched: ";
    cin>>value;
    struct node *s;
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
void single_llist::reverse()
{
    struct node *prev=NULL, *temp=head, *next=NULL;
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
void single_llist::display()
{
    struct node *temp;
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
