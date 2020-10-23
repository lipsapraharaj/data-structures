#include<iostream>
#include<conio.h>
using namespace std;

int arr[40],int n;
int binary_search(int left,int right, int x)
{
     int mid;
 
      if(right>=left)
    {
      mid=left+(right-1)/2;
     
     if(arr[mid]==x)
       return mid;
    
     if(arr[mid]>x)
       return binary_search(left,mid-1,x);
   
    return binary_search(mid+1,right,x)
   }
     return -1;
}

int main()
{
   int x,b;
      
        cout<<"Enter number of elements in the array: ";
        cin>>n;
        for(int i=0;i<=n;i++)
        {
          cout<<"\nEnter the element number: "<<i+1<<" : ";
          cin>>arr[i];
         }
         
       cout<<"\nThe array you entered is: ";
           for(int i=0;i<n;i++)
           {
             cout<<" "<<arr[i];
           }
       cout<<"\nEnter the element you want to search: ";
       cin>>x;
       
      b=binary_search(0,n-1,x);
      if(b==-1)
      {
        cout<<\nElement cannot be found!!!";
      }
      else
      {
        cout<<"\nElement has been found at index number: "<<b;
      }

     return 0;
}
