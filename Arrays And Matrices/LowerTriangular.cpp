#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
class lower
{
    int *arr;
    int n;
public:
    lower(int size=20)
    {
        int i,j;
        n=size;
        if(size!=0)
        arr=new int[n*(n+1)/2];
        else
            arr=0;

    }
    ~lower()
    {
        delete []arr;

    }
    void store(int,int ,int);
    int retrieve(int,int);
    void display();

};

void lower::store(int ele,int i,int j)
 {
     int k=0;
     if(i<0 || i>n || j<0 || j>n)
     {
         cout<<"Out of Bound!!";
         exit(0);
     }

     else if(i>=j)
     {
         k=(i*(i-1)/2+j-1);
         arr[k]=ele;
     }

     else if(ele!=0)

         cout<<"\nMust be zero";
 }

 int lower::retrieve(int i,int j)
 {
    if(i<0 || j<0 || i>n || j>n)
    {
        cout<<"Out of Bound!!";
        exit(0);
    }
    else if(i<j)
    {
        return 0;
    }

    else
    {
       int k=arr[i*(i-1)/2+j-1];
       return k;
    }
 }

 void lower::display()
 {
     int k;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(i<j)
                cout<<"0"<<"\t";
             else
             {
                  k=i*(i-1)/2+j-1;
                cout<<arr[k]<<"\t";
             }
         }
         cout<<"\n";
     }
 }

 int main()
 {
     int rows=0,columns=0,i=0,j=0;
     int ele;
     char ch;
     cout<<"Enter the number of rows and columns of the matrix: ";
     cin>>rows>>columns;
     if(rows!=columns)
     {
         cout<<"INVALID ENTRY OF SIZE!!";
         exit(0);
     }
     lower l(rows);
     do
     {
         cout<<"\nEnter the element,row and column of Lower Triangular matrix: \n";
         cin>>ele>>i>>j;
         l.store(ele,i,j);
         cout<<"\nEnter your choice: ";
         cin>>ch;
     }while(ch=='y' || ch=='Y');

    cout<<"\nThe Lower Triangular Matrix is: "<<"\n";
    l.display();
    cout<<"\nEnter the position for retrieval of element from lower triangular matrix: ";
    cin>>i>>j;
    int val=l.retrieve(i,j);
    cout<<"\nRetrieved element is: "<<val;
    cout<<endl;
    return 0;

 }
