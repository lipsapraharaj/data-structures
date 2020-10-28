#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
class upper
{
    int *arr;
    int n;
public:
    upper(int size=20)
    {
        int i,j;
        n=size;
        if(size!=0)
        arr=new int[n*(n+1)/2];
        else
            arr=0;

    }
    ~upper()
    {
        delete []arr;

    }
    void store(int,int ,int);
    int retrieve(int,int);
    void display();

};

void upper::store(int ele,int i,int j)
 {
     int k=0;
     if(i<0 || i>n || j<0 || j>n)
     {
         cout<<"Out of Bound!!";
         exit(0);
     }

     else if(i<=j)
     {
         k=(n*i)-i*(i+1)/2+j;
         arr[k]=ele;
     }

     else
        cout<<"\nMust be zero";
 }

 int upper::retrieve(int i,int j)
 {
     int k;
    if(i<0 || j<0 || i>n || j>n)
    {
        cout<<"Out of Bound!!";
        exit(0);
    }
    else if(i>j)
    {
        return 0;
    }

    else
    {
        k=arr[(n*i)-i*(i+1)/2+j];
       return k;
    }
 }

 void upper::display()
 {
     int k=0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(i>j)
                cout<<"0"<<"\t";
             else
             {
                  k=(n*i)-i*(i+1)/2+j;
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
     upper u1(rows);
     do
     {
         cout<<"\nEnter the element: ";
         cin>>ele;
         cout<<"\nEnter the row and column for the element in Upper Triangular matrix: \n";
         cin>>i>>j;
         u1.store(ele,i,j);
         cout<<"\nEnter your choice: ";
         cin>>ch;
     }while(ch=='y' || ch=='Y');

    cout<<"\nThe Upper Triangular Matrix is: "<<"\n";
    u1.display();
    cout<<"\nEnter the position for retrieval of element from upper triangular matrix: ";
    cout<<"\nEnter row: ";
    cin>>i;
    cout<<"\nEnter column: ";
    cin>>j;
    int val=u1.retrieve(i,j);
    cout<<"\nRetrieved element is: "<<val;
    cout<<endl;
    return 0;

 }
