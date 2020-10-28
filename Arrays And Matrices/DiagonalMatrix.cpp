#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
class diagonal
{
    int *arr;
    int n;
public:
    diagonal(int size=20)
    {
        n=size;
        if(size!=0)
        arr=new int[n];
        else
            arr=0;

    }
    ~diagonal()
    {
        delete []arr;

    }
    void store(int,int ,int);
    int retrieve(int,int);
    void display();

};

 void diagonal::store(int ele,int i,int j)
 {
     if(i<0 || i>n )
     {
         cout<<"Out of Bound!!";
         exit(0);
     }

     else if(i>j && ele!=0)
     {
         cout<<"Must be zero";
     }

     else if(i==j)
     {
         arr[i]=ele;
     }
 }

 int diagonal::retrieve(int i,int j)
 {
    if(i<0 || j<0 || i>n || j>n)
    {
        cout<<"Out of Bound!!";
        exit(0);
    }
    else if(i==j)
    {

        return arr[i];
    }

    else
       return 0;
 }

 void diagonal::display()
 {
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(i!=j)
                cout<<"0"<<"\t";
             else
                cout<<arr[i]<<"\t";

         }
         cout<<"\n";
     }
 }

 int main()
 {
     int rows=0,columns=0,i=0,j=0;
     int ele;
     cout<<"Enter the number of rows and columns of the matrix: ";
     cin>>rows>>columns;
     if(rows!=columns)
     {
         cout<<"INVALID ENTRY OF SIZE!!";
         exit(0);
     }
     diagonal d1(rows);
     cout<<"\nEnter the elements in the matrix: ";
     for(i=0,j=0;i<rows,j<columns;i++,j++)
     {
        cin>>ele;
        d1.store(ele,i,j);
     }
    cout<<"\nThe Diagonal Matrix is: "<<"\n";
    d1.display();
    cout<<"\nEnter the position for retrieval of element from diagonal matrix: ";
    cin>>i>>j;
    int val=d1.retrieve(i,j);
    cout<<"\nRetrieved element is: "<<val;
    cout<<endl;
    return 0;

 }
