template <class T> 
class stack
{
    private:
       T num[100];
       T top;
    public:
        stack();    //default constructor
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void clear();
        
};

stack<T>::stack(){
    top=-1;
}

template <class T> 
int stack<T>::isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;   
}

template <class T> 
int stack<T>::isFull()
{
    if(top==(size-1))
        return 1;
    else
        return 0;
}

template <class T> 
int stack<T>::push(T n)
{
    //check stack is full or not
    if(isFull())
{     cout<<"Stack Overflow";
        return 0;
    }
else
{
    ++top;
    num[top]=n;
    return n;
  }
}

template <class T> 
int stack<T>::pop()
{
    //to store and print which number is deleted
    T temp;
    //check for empty
    if(isEmpty())
{  cout<<"Stack Underflow";
        return 0;
}
  else
{
    temp=num[top];
    --top;
    return temp;
     }
}

template <class T>
void stack<T>::clear()
{
while(!this->isEmpty())
this->pop();
}
