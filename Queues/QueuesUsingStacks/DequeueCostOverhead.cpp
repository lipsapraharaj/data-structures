#include <iostream>
#include <conio.h>
#include<stack.h>
using namespace std;

class queue
{
  int front,size=10,rear;
  Stack s1, s2;

public:
        queue();
        int isEmpty();
        int isFull();
        void enqueue(int data);
        void dequeue();
        int front();
        void clear();
        void display();
};
        queue::queue()
  {
    front=rear=-1;
  }
        

int queue::isEmpty()    // Check if the queue is empty
{
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

int queue::isFull()    // Check if the queue is full
{
    if(rear == (size-1))
        return 1;
    return 0;
}

int queue::front()        // Returns element that is at front of queue 
  {
    if (isEmpty())
    {
      cout << "Queue is Empty";
      
    }
    return front;
  }

void queue :: clear()
{
    if(!isEmpty())
    {
        front = rear = -1;
        s1->clear();
        s2->clear();
       
        
    }
}


void queue :: enqueue(int x)   // Adding an element
{
    if(isFull())
    {
        cout<<"Queue is Full\n";
       
    }
    else if(isEmpty())
    {
        s1.push(x);
        front++;
        rear++;
    }
    else
    {
        s1.push(x);
        rear++;
    }   
}

void queue :: dequeue()    // Removing an element
{
    if(isEmpty())
    {
        cout<<"Empty Queue\n";
        
    }
    else if(front == rear)
    {
        front = rear = -1;
        cout<<s1.pop();
    }
    else
    {
        front++;
        while(s1.returnTop()!=-1)
        {
            s2.push(s1.pop());
        }
        cout<<s2.pop();
        while(s2.returnTop()!=-1)
        {
            s1.push(s2.pop());
        }
    }
}

void queue::display()      //To display status of the Queue
  {
    if (isEmpty())
    {
      cout << "Queue is Empty";
      return;
    }
    cout << "Queue: ";
    s1.display();
  
  }



int main()
{
    int data,ch;
    queue q;
 
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Clear all the elements of queue"<<endl;
   cout<<"5) Return the front elemnt of queue"<<endl;
   cout<<"6) Exit"<<endl;
   do {
      cout<<"Enter your choice : "<<endl;
      cin<<ch;
      switch (ch) 
     {
         case 1: 
         cout<<"Enter the element : ";
         cin>>data;
         q.enqueue(data);
         break;
         case 2: q.dequeue();
         break;
         case 3: q.display();
         break;
         case 4: q.clear();
         break;
         case 5: q.front();
         break;
         case 6: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=6);
   return 0;
}

