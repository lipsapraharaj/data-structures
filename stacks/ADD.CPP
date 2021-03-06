#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

#define MAX 10

class Stack
{
  int arr[MAX];

 public:

     int item,r;
     int top;

     Stack()
     {
      top=-1;
     }  

     void push(int a)
     {
      if(top==MAX)
        cout<<"\nStack is full";
      else
          arr[++top] = a;
     }

     int pop()
     {
      if(top!=-1)
        return arr[top--];
     }

     void clear()
     {
         while(top!=-1)
         {
          cout<<arr[top--];
         }

         
     }
};



int main()
{
    Stack s1,s2,s3;
    int temp=0;
    int sum=0,n;
    cout<<"\nEnter the first number digit by digit & -1 when finished : ";
    for (int i = 0; n != -1; ++i)
    {
      cin>>n;
      if (n != -1)
      {
         s1.push(n);
      }
    }
    n=0;
    cout<<"\nEnter the second number digit by digit & -1 when finished : ";
    for (int i = 0; n != -1; ++i)
    {
       cin>>n;
       if (n != -1)
       {
          s2.push(n);
       }
    }
    temp = 0;
    while(s1.top!=-1 && s2.top!=-1)
    {
       temp = temp+s1.pop()+s2.pop();
       s3.push(temp%10);
       temp=temp/10;
    }
    if (s1.top!=-1)
    {
      while(s1.top!=-1)
      {
        s3.push(temp+s1.pop());
        temp=0;
      }
    }
    if (s2.top!=-1)
    {
      while(s2.top!=-1)
      {
        s3.push(temp+s2.pop());
        temp=0;
      }
    }  
    if (temp!=0)
    {
      s3.push(temp);
    }

    cout<<"\nThe Result is : ";
    s3.clear();

  return 0;
}
