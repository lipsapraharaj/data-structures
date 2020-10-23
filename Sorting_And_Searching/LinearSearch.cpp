#include<iostream>
#include<conio.h>
using namespace std;

int linear_search(int arr[],int n,int x)
{
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			return i;   //if the element is present in array,then returns it's index number
		}
            return -1;     //if the element is not present in the array
	}


int main()         
{
   int x,arr[40],n;

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
       int l=linear_search(arr[],n,x);

       if(l==-1)
       {
         cout<<"\nElement cannot be found!!!";
       }

        else
         {
           cout<<\n"Element has been found at index number: "<<l;
		
	return 0;
}