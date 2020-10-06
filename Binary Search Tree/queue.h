class Queue
{
    node *front,*rear,*prev,*temp;
    int x;
    node *next;
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