#include <iostream>
#include<conio.h>
#define SIZE 5 
using namespace std;

template<class T>
class  Circular_Queue
 {
   private:
  T items[SIZE], front, rear;

   public:
        Circular_Queue();
        void enqueue(int item);				 
        void dequeue();
        void display();
        void clear();
	int front();
	bool isEmpty();
	bool isFull();
};
   template <class T>       
   Circular_Queue<T>::Circular_Queue() 
  {
    front = -1;
    rear = -1;
  }

 
  template <class T>
  bool  Circular_Queue<T>::isFull()     // Check if the queue is full
{
    if (front == 0 && rear == SIZE - 1) 
{
      return true;
    }
    if (front == rear + 1) 
{
      return true;
    }
    return false;
  }

  
  template <class T>
  bool Circular_Queue<T>::isEmpty()    // Check if the queue is empty
  {
    if (front == -1)
      return true;
    else
      return false;
  }

   template <class T>
   void Circular_Queue<T>::clear()
  {
    front=rear=-1;
  }

  template <class T> 
  int Circular_Queue<T>::front()  // Returns element that is at front of queue 
  {
    if(isEmpty())
    {
      cout<<"Cannot return front element from empty queue\n";
     
     }
      return (T items[front]);
   }

  template <class T>
  void Circular_Queue<T>::enqueue(T element)    // Adding an element
 {
    if (isFull()) 
   {
      cout << "Queue is full";
    } 
     else 
   {
      if (front == -1) front = 0;
      rear = (rear + 1) % SIZE;
     T items[rear] = element;
      cout << endl
         << "Inserted " << element << endl;
    }
  }

  template <class T>
  int Circular_Queue<T>::dequeue()    // Removing an element
  {
    T element;
    if (isEmpty()) 
   {
      cout << "Queue is empty" << endl;
      return (-1);
    } 
      else
 {
      element = T items[front];
      if (front == rear) 
    {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else
 {
        front=(front+1) % SIZE;;
      }
      return (element);
    }
  }


  template <class T>
  void Circular_Queue<T>::display()    //To display status of Circular Queue
{
    if (isEmpty())
  {
      cout << endl
         << "Empty Queue" << endl;
    } 
      else 
   {
      cout << "Front -> " << front;
      cout << endl
         << "Items -> ";
      for (int i = front; i != rear; i = (i + 1) % SIZE)
        cout << T items[i];
      cout <<T items[i];
      cout << endl
         << "Rear -> " << rear;
    }
  }
};
  
int main()
{
    int choice, item;
    Circular_Queue<int> cq;
    do
    {
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.Display the elements of queue\n";
        cout<<"4.Clear the queue\n";
        cout<<"5.Return the front element of the queue\n";
        cout<<"6.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element:";
            cin>>item;
            cq.enqueue(item);
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
            cout<<"Exit"<<endl;
	    break;
	default:
	    cout<<"Wrong choice\n";
	}/*End of switch*/
    }
    while(choice != 6);
    return 0;
}
