#include<iostream>
#include<conio.h>
using namespace std;

void max_heapify(int arr[], int n, int i)
{
   int largest=i,temp;
   int left=2*i;
   int right=2*i+1;

    if (left <= n && arr[left] > arr[largest])
            largest=left;

    if (right <= n && arr[right]>arr[largest])
        {  
    largest=right;
}
else
{
largest=i;
}
     if (largest!=i)
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=arr[i];

    max_heapify(arr,n,largest);
}


void building_maxheap(int arr[],int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(arr,n,i);
    }
}


int main()
{
    int n, i;
    cout<<"Enter the number of elements for array\n";
    cin>>n;
    int arr[n];
     for (i = 1; i <= n; i++)
    {
        cout<<"Enter the element in array: ";
        cin>>arr[i];
    }

    building_maxheap(arr,n);
    cout<<"Max Heap\n";
    for (int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<endl;
    }


    getch();
    return 0;
}
