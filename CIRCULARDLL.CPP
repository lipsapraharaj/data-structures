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
    struct node<X> *prev;
}*start, *last;
int counter = 0;
/*
 * Class Declaration
 */
template<class X>
class double_clist
{
    public:
        void add_begin(int value);
        void add_pos(int value, int position);
        void add_last(int value);
        void delete_front(int value);
        void delete_pos(int value,int position);
        void delete_last(int value);
        void search_element(int value);
        void display_list();
        void count();
        double_clist()
        ~double_clist()
        {
            start = NULL;
            last = NULL;			
        }
};
 
/*
 * Main: Contains Menu
 */
int main()
{
    int choice;
    double_clist<int> cdl;
    while (1)
    {   cout<<endl<<"\n---------------------------"<<endl;
        cout<<endl<<" Operations on Circular Doubly linked list"<<endl;
        cout<<endl<<"---------------------------"<<endl;     
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at beginning"<<endl;
        cout<<"3.Add at a position"<<endl;
        cout<<"4.Add at the end"<<endl;
        cout<<"5.Delete from front"<<endl;
        cout<<"6.Delete from a position"<<endl;
        cout<<"7.Delete from end"<<endl;
        cout<<"8.Search"<<endl;
        cout<<"9.Display"<<endl;
        cout<<"10.Count the number of nodes"<<endl;
        cout<<"11.Reverse the list"<<endl
        cout<<"12.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cdl.create_node(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cdl.insert_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element at a position: ";
            cin>>position;
            cdl.insert_pos(element, position);
            cout<<endl;
            break;
         case 4:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element at end: ";
            cin>>position;
            cdl.insert_last(element);
            cout<<endl;
            break;
        case 5:
            if (last == NULL)
            {
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cdl.delete_front(element);
            cout<<endl;
            break;
          case:6
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cdl.delete_pos(element,position);
            cout<<endl;
            break;            
          case:7
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cdl.delete_last(element);
            cout<<endl;
            break;
            
          case 8:
            if (last == NULL)
            {
                cout<<"List Empty!! Can't search"<<endl;
                break;
            }
            

            cout<<"Enter the element to be searched: ";
            cin>>element;
            cdl.search_element(element);
            cout<<endl;
            break;

        case 9:
            cdl.display_list();
            break;
            
        case 10:
            cout<<"The number of nodes in the list are";
            cdl.count();
            break;    
        case 1:
            cout<<"The reverse of the list is:";
            cdl.reverse();
            break;    
        case 12:
             exit(1);
            break;                       
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
 
/*
 * Destructor 
 */
void double_clist<X>::~double_clist()
     {
    
        if (this->isEmpty())
  
        struct node<X> *ptr, *temp = tail->next;
   
       while (temp!= tail)
    
    {
      
     ptr = temp;
      
     temp = ptr->next;
      
     delete ptr;
    
    }
    
     delete temp;
    
     tail = NULL;
    
     return 0;
  
   }

/*
 *INSERTS NODE AT BEGINNING
 */
template<class X>
void double_clist<X>::insert_begin()
{
    int value;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    struct node<X> *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {    
        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
        start->prev = last;
        last->next = start;
        cout<<"Element inserted"<<endl;
    }
}
 
/*
 *INSERTS NODE AT LAST
 */
template<class X>
void double_clist<X>::insert_last()
{
    int value;    
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value; 
    struct node<X> *temp;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;    
        start->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        start->prev = last;
        last->next = start;
    }
}
/*
 *INSERTS NODE AT A POSITION
 */
template<class X>
void double_clist<X>::insert_pos()
{    
    int value, pos, i;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    cout<<endl<<"Enter the postion of element inserted: ";
    cin>>pos;
    struct node<X> *temp, *s, *ptr;
    temp = create_node(value);
    if (start == last && start == NULL)
    {
        if (pos == 1)
        {
            start = last = temp;
            start->next = last->next = NULL;    
            start->prev = last->prev = NULL;
        }
        else
        {
            cout<<"Position out of range"<<endl;
            counter--;
            return;
        }
    }  
    else
    {
        if (counter < pos)
        {
             cout<<"Position out of range"<<endl;
             counter--;
             return;   		
        }
        s = start;		
        for (i = 1;i <= counter;i++)
        {
            ptr = s;
            s = s->next;
            if (i == pos - 1)
            {
                ptr->next = temp;
                temp->prev = ptr;
                temp->next = s;
                s->prev = temp;
                cout<<"Element inserted"<<endl;
                break;
            }
        }
    }
}
/*
 * Deletes Node  From The Beginning
 */
template<class X>
void double_clist<X>::delete_front()

  {
    
      if (this->isEmpty())
    
   {
      
         cout << "\nList is empty...\n";
      
         return;
    
        }
    
          if (tail->next == tail)
    
         {
      
          delete tail;
      
          tail = NULL;
    
         }
    
            else
    
         {
      
           struct node<X> *temp = tail->next;
      
           tail->next = temp->next;
      
           temp->next->prev = tail;
      
           delete temp;
    
         }
    
           cout << "\nDeleted node at front...";
    
           this->display();
   
  
         }

  
/*
 * Deletes Node  From A Position
 */
template<class X>
void double_clist<X>::delete_pos(element,loc)

         {
    
           if (this->isEmpty())
    
         {
      
           cout << "\nList is empty...\n";
    
          }
    
           int size = this->count();
    
           if (loc > size || loc < 1)
    
          {
      
           cout << "Invalid location...\n";
         
          }
    
           if (loc == size)
    
           {
      
             this->deleteBack();
   
           }
    
             struct node<X> *temp = tail->next;
    
             for (int i = 1; temp->next != tail && i < loc; i++)
      
             temp = temp->next;
    
             temp->prev->next = temp->next;
    
             temp->next->prev = temp->prev;
    
             delete temp;
    
             cout << "Deleted node "
<< "at location " << loc << "...";
    
             this->display();
   
           }

  


/*
 * Deletes Node  From The End
 */
template<class X>
void double_clist<X>::delete_last(element)  
           {
    
             if (this->isEmpty())
    
           {
      
             cout << "\nList is empty...\n";
    
           }
    
             if (tail->next == tail)
    
           {
      
              delete tail;
      
              tail = NULL;
    
            }
    
             else
    
           {
      
              struct node<X> *temp = tail;
      
              tail = temp->prev;
      
              tail->next = temp->next;
     
              delete temp;
    
           }
    
             cout << "\nDeleted node at back...";
   
             this->display();
   
            }

/*
 * Search Element in the list
 */
template<class X>
void double_clist<X>::search()
{
    int pos = 0, value, i;
    bool flag = false;
    struct node<X> *s;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to search"<<endl;
        return;
    }
    cout<<endl<<"Enter the value to be searched: ";
    cin>>value;
    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->info == value)
        {
            cout<<"Element "<<value<<" found at position: "<<pos<<endl;
            flag = true;
        }    
        s = s->next;
    }
    if (!flag)
        cout<<"Element not found in the list"<<endl;   
}

/*
 * Display Elements of the List 
 */
template<class X>
void double_clis<X>t::display()
{
    int i;
    struct node<X> *s;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to display"<<endl;
        return;
    }
    s = start;
    for (i = 0;i < counter-1;i++)
    {	
        cout<<s->info<<"<->";
        s = s->next; 
    }
    cout<<s->info<<endl;
}

/*
 * Reverse Doubly Circular Linked List 
 */
template<class X>
void double_clist<X>::reverse()
{
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to reverse"<<endl;
        return;
    }
    struct node<X> *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != start)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    last = start;
    start = p1;
    cout<<"List Reversed"<<endl; 	 
}


/*
 * Counts the No. Of Nodes Of The List 
 */
template<class X>
int double_clist<X>::count()

     {
    
      if (this->isEmpty())
    
     {
      
      cout << "\nList is empty...\n";
      
      return -1;
    
     }
    
      int count = 0;
    
      struct Node<X> *temp = tail->next;
    
     do
    
    {
      
      temp = temp->next;
      
      count++;
    
    }     while (temp != tail->next);
    
      return count;
  
    }

/*
 * Reverse Doubly Circular Linked List 
 */
template<class X>
void double_clist<X>::reverse()
{
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to reverse"<<endl;
        return;
    }
    struct node<X> *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != start)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    last = start;
    start = p1;
    cout<<"List Reversed"<<endl; 	 
}