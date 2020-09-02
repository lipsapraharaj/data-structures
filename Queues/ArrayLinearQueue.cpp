#include <iostream>
#include<conio.h>
#include <cstdlib>
using namespace std;
#define SIZE 10

class queue
{
   	  int *arr,size,front = - 1, rear = - 1;
public:
	queue();	
	~queue();				 
        void dequeue();
	void enqueue(int x);
        void display();
        void clear();
	int front();
	int isEmpty();
	int isFull();
};

// Constructor to initialize queue
queue::queue(int size=10)
{
	front=rear=-1;
        this->size=size;
        arr=new int[size];
        for(int i=0;i<size;++i)
        q[i]=0;
        
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
	delete[] arr;
}

int queue::isEmpty()
{
     if(front==-1 && rear==-1)
     return 1;
}

int queue::isFull()
{
     if(rear==(size-1))
     return 1;
}

void queue::clear()
{
front=rear=-1;
}

// Inserts an element in Queue 
void queue::enqueue(int x)
	{
		cout<<"Enqueuing "<<x<<" \n";
		if(isFull())
		{
			cout<<"Error: Queue is Full\n";
			
		}
		 else if (isEmpty())
		{ 
		    front++;
                    rear++;
                    arr[front]=x; 
		}
		else
		{
		  if(isFull()==0)
               {
                  arr[++rear] = x;
		}
           }
	}

// Removes an element in Queue from front end
void queue::dequeue()
     {
		cout<<"Dequeuing \n";
		if(isEmpty())
		{
			cout<<"Error: Queue is Empty\n";
			
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front++;
                        
		}
	}

// Returns element that is at front of queue 
int queue::front()
    {
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
		return arr[front];
	}

void queue::display()
{
  if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else 
 {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<arr[i]<<" ";
         cout<<endl;
   }
        

int main() 
{
   int ch;
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
         cin>>x;
         q.enqueue(x);
         break;
         case 2: q.dequeue();
         break;
         case 3: q.display();
         break;
         case 4: q.clear();
         break;
         case 5: q.clear();
         break;
         case 6: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=6);
   return 0;
}