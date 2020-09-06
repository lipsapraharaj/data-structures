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
        bool isEmpty();
        bool isFull();
        void enqueue(int data);
        int dequeue();
        int front();
        void clear();
        void display();
};

  queue::queue()
  {
    front=rear=-1;
  }

    bool queue::isEmpty()     // Check if the queue is empty
  {
    return s1.isEmpty() && s2.isEmpty();
  }


   bool queue::isFull()     // Check if the queue is full
{
    if(rear == (size-1))
        return true;
     else
    return false;
}

  
  void queue::enqueue(int data)     // Adding an element
    while (s1.isEmpty())
      s2.push(s1.pop());
    if (s1.push(data))
    {
      rear = s1.top();
      while (!s2.isEmpty())
        s1.push(s2.pop());
    }
    front = s1.top();
    return 1;
  }

  int queue::dequeue()     // Removing an element
  {
    if (s1.isEmpty())
    {
      cout << " Queue is Empty\n";
      
    }
    int temp =s1.pop();
    if (s1.isEmpty())
      front = rear =-1;
    else
      front =s1.top();
    return temp;
  }

  int queue::front()        // Returns element that is at front of queue 
  {
    if (isEmpty())
    {
      cout << "Queue is Empty";
      
    }
    return front;
  }

 
  void queue::clear()     
  {
    this->s1.clear();
    this->s2.clear();
    this->front = this->rear = -1;
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



  
  