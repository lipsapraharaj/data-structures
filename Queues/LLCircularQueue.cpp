#include<iostream.h>
#include<conio.h>
#include<process.h>

struct node
{
    int data;
    node *next;
};
class Circular_queue
{
    node *rear;
public:
        Circular_queue();
        void enqueue(int data);				 
        void dequeue();
        void display();
        void clear();
	int front();
	bool isEmpty();
};
    Circular_queue()
    {
        rear=NULL;
    }

    bool Circular_queue::isEmpty()   // Check if the queue is empty
  {
     if(rear==NULL)
          return true;
      else
        return false;
  }  


     void Circular_queue::clear()    //Clears the queue
    {
     while(!isEmpty())
     {
       this->dequeue();
      }
    }
     void Circular_queue::front()    // Returns element that is at front of queue 
      {
        if(isEmpty())
      {
        cout<<"Empty Queue";
      }
    return front->data
 
       }
        
   
    void Circular_queue::enqueue(int data)     // Inserting an element
    {
        node *p=new node;
        p->data=data;
        if(isEmpty())
        {
            rear=p;
            rear->next=p;
        }
        
        else
        {
            p->next=rear->next;
            rear->next=p;
            rear=p;
        }
    }
    void Circular_queue::dequeue()      // Deleting  an element
    {
        if(isEmpty())
            cout<<"Queue Empty";
        else
        {
            node *t=rear->next;
            cout<<"The element to be deleted is"<<rear->next->data;
            if(rear==t)
                rear=NULL;
            else
            {
                rear->next=t->next;
                delete t;
            }
        }
    }
    void Circular_queue::display()    //To display status of Circular Queue
    {
        node *t=rear;
        if(isEmpty())
            cout<<"Queue is Empty";
        else
        {
            do
            {
                t=t->next;
                cout<<t->data<<" ";
            }while(t!=rear);
        }
    }
};

void main()
{
    clrscr();
    Circular_queue cq;
    int data,choice;
    while(1)
    {
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Display the elements of queue\n";
        cout<<"4.Clear the queue\n";
        cout<<"5.Return the front element of the queue\n";
        cout<<"6.Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice";
        switch(choice)
        {
            case 1:
                    cout<<"\nEnter the element to be inserted";
                    cin>>data;
                    cq.enqueue(data);
                    break;
            case 2:
                    cq.dequeue();
                    break;
            case 3:
                    cq.display();
                    break;
            case 4:
                    cq.clear();
                    break;
            case 5:
                    cq.front();
                    break;
            case 6:
                    exit(0);
        }
    }
}
