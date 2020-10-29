#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
class symmetric
{
    int *arr;
    int n;
public:
    symmetric(int size=20)
    {
        int i,j;
        n=size;
        if(size!=0)
        arr=new int[n*(n+1)/2];
        else
            arr=0;

    }
    ~symmetric()
    {
        delete []arr;

    }
    void store(int,int ,int);
    int retrieve(int,int);
    void display();

};

void symmetric::store(int ele,int i,int j)
 {
     int k=0;
     if(i<1 || i>n || j<1 || j>n)
     {
         cout<<"Out of Bound!!";
         exit(0);
     }

    if(i<j) return;
     {
         k=i*(i-1)/2+j-1;
         cout<<"Array index position: "<<k;
         arr[k]=ele;
     }


 }

 int symmetric::retrieve(int i,int j)
 {
     int temp;
    if(i<1 || j<1 || i>n || j>n)
    {
        cout<<"Out of Bound!!";
        exit(0);
    }
    if(i<j)
    {
        temp=i;
        i=j;
        j=temp;
    }

        return arr[i*(i-1)/2+j-1];
}


 void symmetric::display()
 {
     int k;
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=n;j++)
         {
             if(i<j)
                cout<<arr[j*(j-1)/2+i-1]<<"\t";
             else
             {
                cout<<arr[i*(i-1)/2+j-1]<<"\t";
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
     cout<<"\nEnter the no. of rows: ";
     cin>>rows;
     cout<<"\nEnter the no.of columns:";
     cin>>columns;
     if(rows!=columns)
     {
         cout<<"INVALID ENTRY OF SIZE!!";
         exit(0);
     }
     symmetric sy(rows);
     cout<<"\nEnter the  elements of symmetric matrix: \n";
     for(i=1;i<=columns;i++)
     {
         for(j=1;j<=i;j++)
         {
             cin>>ele;
             sy.store(ele,i,j);
         }
     }
    cout<<"\nThe Symmetric Matrix is: "<<"\n";
    sy.display();
    cout<<"\nEnter the position for retrieval of element from upper triangular matrix: ";
    cout<<"\nEnter row: ";
    cin>>i;
    cout<<"\nEnter column: ";
    cin>>j;
    int val=sy.retrieve(i,j);
    cout<<"\nRetrieved element is: "<<val;
    cout<<endl;
    return 0;

 }

