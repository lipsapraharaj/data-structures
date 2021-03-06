#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
template <class X>
struct node
{
    X info;
    struct node<X> *next,;
}*last
 
/*
 * Class Declaration
 */
template <class X>
class circular_llist
{
    public:
        void add_begin(int value);
        void add_pos(int value, int position);
        void add_last(int value);
        void delete_front(int value);
        void delete_pos(int value,int position);
        void delete_last(int value);
        void search_element(int value);
        void reverse();
        void display_list();
        void count();
        circular_llist()
        ~circular_llist()
        {
            last = NULL;           
        }
};
 
/*
 * Main :contains menu 
 */
int main()
{
    int choice, element, position;
    circular_llist<int> cl;
    while (1)
    {
        cout<<endl<<"---------------------------"<<endl;
        cout<<endl<<"Circular singly linked list"<<endl;
        cout<<endl<<"---------------------------"<<endl;     
        cout<<"1.Add at beginning"<<endl;
        cout<<"2.Add at a position"<<endl;
        cout<<"3.Add at the end"<<endl;
        cout<<"4.Delete from front"<<endl;
        cout<<"5.Delete from a position"<<endl;
        cout<<"6.Delete from end"<<endl;
        cout<<"7.Search"<<endl;
        cout<<"8.Reverse"<<endl;
        cout<<"9.Display"<<endl;
        cout<<"10.Count the number of nodes"<<endl;
        cout<<"11.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cl.add_begin(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element at a position: ";
            cin>>position;
            cl.add_pos(element, position);
            cout<<endl;
            break;
         case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element at end: ";
            cin>>position;
            cl.add_last(element);
            cout<<endl;
            break;
        case 4:
            if (last == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.delete_front(element);
            cout<<endl;
            break;
          case 5:
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.delete_pos(element,position);
            cout<<endl;
            break;
            
          case 6:
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.delete_last(element);
            cout<<endl;
            break;
            
          case 7:
            if (last == NULL)
            {
                cout<<"List Empty!! Can't search"<<endl;
                break;
            }
            

            cout<<"Enter the element to be searched: ";
            cin>>element;
            cl.search_element(element);
            cout<<endl;
            break;

        case 8:
            cout<<"The reverse of the circular list is"
            cl.reverse();
            break;    
        case 9:
            cl.display_list();
            break;
        
        case 10:
            cout<<"The number of nodes in the list are";
            cl.count();
            break;                      
        case 11:
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
 
void circular_llist<X>::circular_llist()
    {
        head = temp = 0;
        totalNodes = 0;
    }

/*
 * Destructor
 */
    void circular_llist<X>::~circular_llist()
    {
        system("CLS");
        temp = head;
        Node<X> *nextNodePtr;
        cout<<"Destroying The List\n";
        while(temp->nextNode != head)
        {
            nextNodePtr = temp->nextNode;
            delete temp;
            temp = nextNodePtr;
        }
        delete temp;
        cout<<"\nDone.\n";
    }

/*
 * Insertion of element at beginning 
 */
template <class X>
void circular_llist<X>::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node<X> *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}
 
/*
 * Insertion of element at a particular place 
 */
template <class X>
void circular_llist<X>::add_pos(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node<X> *temp, *s;
    s = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }
    temp = new(struct node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;


    /*Element inserted at the end*/
template <class X>
void circular_llist<X>::add_last(int value)
    if (s == last)
    { 
        last=temp;
    }

 
/*
 * Deletion of element from the list
 */
template <class X>
void circular_llist<X>::delete_front(int value)
{
    struct node<X> *temp, *s;
    s = last->next;
      /* If List has only one element*/
    if (last->next == last && last->info == value)  
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    if (s->info == value)  /*First Element Deletion*/
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }
    while (s->next != last)
    {
        /*Deletion of Element in between*/

template <class X>
void circular_llist<X>::delete_pos(int value,int pos)
        if (s->next->info == value)    
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        s = s->next;
    
    /*Deletion of last element*/
template <class X>
void circular_llist<X>::delete_last(int value)
    if (s->next->info == value)    
    {
        temp = s->next;
        s->next = last->next;
        free(temp);		
        last = s;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}
 
/*
 * Search element in the list 
 */
template <class X>
void circular_llist<X>::search_element(int value)
{
    struct node<X> *s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)    
        {
            cout<<"Element "<<value; 
            cout<<" found at position "<<counter<<endl;
            return;
        }
        s = s->next;
    }
    if (s->info == value)    
    {
        counter++;             
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found in the list"<<endl;
}
 

/*
 * Reverse Circular Link List 
 */
template <class X>
void circular_llist<X>::reverse(struct node *head) 
{
    
    struct node<X> *prev, *cur, *next, *last;

    // Cannot reverse empty list
    if (*head == NULL)
    {
        cout<<"Cannot reverse empty list.\n";
        
    }


    
    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

   
    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head = prev;       // Make last node as head
}



/*
 * Display Circular Link List 
 */
template <class X>
void circular_llist::display_list()
{
    struct node<X> *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display"<<endl;
        return 0;
    }
    s = last->next;
    cout<<"Circular Link List: "<<endl;
    while (s != last)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<endl;
}
 

/*
 *Count No. Of Nodes In Circular Link List 
 */
template <class X>
int circular_llist<X>::count(struct node* head)
{
   struct node*<X> temp = head;
   int result = 0;
   if (head != NULL){
      do {
         temp = temp->next;
         result++;
      } while (temp != head);
   }
   return result;
}

