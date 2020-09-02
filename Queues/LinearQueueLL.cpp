// Queue - Linked List Implementation
#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
    int x;
    node *next;
};

class Queue
{
    node *front,*rear,*prev,*temp;
}
   
public:
        Queue();					 
        void dequeue();
	void enqueue(int x);
        void display();
        void clear();
	int front();
	int isEmpty();
	int isFull();
 };

    Queue::Queue()
    {
        front = NULL;
        rear = NULL;
    }


     int Queue::isEmpty()
{
	return rear == NULL && front == NULL;
}

    void Queue::clear()
    {
     while(!isEmpty())
     {
       this->dequeue();
      }
    }

    int Queue::isFull()
    {
        if (node!= NULL)
	{
		// set the data in allocated node and return the node
		node->data = item;
		node->next = NULL;
		return node;
	}
         else
	{
		cout<<"Queue Overflow");
		
    }
  }

   

// Returns top element in a queue
    int Queue::front()
{
	// check for empty queue
	if (front != NULL)
		return front->data;
	else
		exit(EXIT_FAILURE);
}

// Inserts an element in Queue
    void Queue::enqueue(int x)
    {
        temp = new node;
        temp->data = x;
        temp->next = NULL;

       if(isEmpty())
       {
            front = temp;
            rear = temp;
        }

          else if(isFull())
     {
       cout<<"Queue is Full\n";
      }

        else
        {
            prev = rear;
            rear->next = temp;
            rear = temp;
        }
    }

// Removes an element in Queue from front end
    void Queue::dequeue()
    {
       if(isEmpty())
{
      cout<<"Queue is empty\n";
    }
        else
   {
        temp = front;
        front = front->next;
        delete temp;
    }

    

    void Queue::display()
    {
        if(!isEmpty())
        {
            for(temp = front; temp != NULL; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "Queue is Empty" << endl;
        }
    }
};

int main()
{
   int ch;
   Queue q;
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
         case 5: q.front();
         break;
         case 6: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=6);
   return 0;
}
}