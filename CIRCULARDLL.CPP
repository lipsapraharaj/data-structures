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
    struct node *prev;
}*start, *last;
int counter = 0;
/*
 * Class Declaration
 */
class double_clist
{
    public:
        void create_node(int value);
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
    double_clist cdl;
    while (1)
    {   cout<<endl<<"\n---------------------------"<<endl;
        cout<<endl<<" Operations on Doubly Circular linked list"<<endl;
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
        cout<<"11.Quit"<<endl;
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
        
        case 11:
             exit(1);
            break;                       
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
 
/*
 *MEMORY ALLOCATED FOR NODE DYNAMICALLY
 */
node* double_clist::create_node(int value)
{
    counter++;  
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
/*
 *INSERTS NODE AT BEGINNING
 */
void double_clist::insert_begin()
{
    int value;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    struct node *temp;
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
void double_clist::insert_last()
{
    int value;    
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value; 
    struct node *temp;
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
void double_clist::insert_pos()
{    
    int value, pos, i;
    cout<<endl<<"Enter the element to be inserted: ";
    cin>>value;
    cout<<endl<<"Enter the postion of element inserted: ";
    cin>>pos;
    struct node *temp, *s, *ptr;
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
void double_clist::delete_front()

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
      
           struct Node *temp = tail->next;
      
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
void double_clist::delete_pos(element,loc)

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
    
             struct Node *temp = tail->next;
    
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
void double_clist::delete_last(element)  
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
      
              struct Node *temp = tail;
      
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
void double_clist::search()
{
    int pos = 0, value, i;
    bool flag = false;
    struct node *s;
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
void double_clist::display()
{
    int i;
    struct node *s;
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
 * Counts the No. Of Nodes Of The List 
 */
int double_clist::count()

     {
    
      if (this->isEmpty())
    
     {
      
      cout << "\nList is empty...\n";
      
      return -1;
    
     }
    
      int count = 0;
    
      struct Node *temp = tail->next;
    
     do
    
    {
      
      temp = temp->next;
      
      count++;
    
    }     while (temp != tail->next);
    
      return count;
  
    }