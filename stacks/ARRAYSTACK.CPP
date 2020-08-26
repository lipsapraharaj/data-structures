#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;

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
        void topel()
        void clear();
        void display();
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
void stack<T>::display()
{
    int i; 
    cout<<"stack is: ";
    for(i=top; i>=0; i--)
    cout<<num[i]<<" ";
    cout<<endl;
}

template <class T>
void stack<T>::clear()
{
while(!this->isEmpty())
this->pop();
}

//returns the top most element of the stack
template <class T>
void stack<T>::topel()
{
if(top>-1)
cout<<num[top];
}
 
int main()
{    
    int choice, n,temp;
    //declare object
    stack<int> stk;
    
     
    do
    {
        cout<<"1. - Push Item"<<endl;
        cout<<"2. - Pop Item"<<endl;
        cout<<"3. - Display Items (Print stack)"<<endl;
        cout<<"4. - Clear the stack"<<endl;
        cout<<"5. - Returning the top most element of stack"<<endl;
        cout<<"6. - Exit"<<endl;         
        cout<<"Enter your choice: ";
        cin>>choice;
         
        switch(choice)
    {
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk.push(n);
                if(temp==0)
                    cout<<"STACK is FULL"<<endl;
                else
                    cout<<temp<<" inserted"<<endl;
            break;
                 
            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY"<<endl;
                else
                    cout<<temp<<" is removed (popped)"<<endl;
            break;
             
            case 3:
                stk.display();
                break;
            case 4:
                 stk.clear();
                 break;
             case 5:
                  stk.topel;
                  break;
            case 6:
                 cout<<"Exiting.."<<endl;
                 exit(1);
                 break;
            default:
                cout<<"An Invalid choice."<<endl;
        }   
    }while(choice!=0);
 
     
    return 0;
     
}