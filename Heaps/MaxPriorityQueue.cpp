#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
using namespace std;

/*
 * Class Declaration
 */
class heap
{
      int arraySize = 20;
      int n;                 //n=heap size
      int *arr;
      const int INF=1000000000;
public:
        int parent(int arr[],int i);
        int left(int i);
        int right(int i);;
        void insert(int arr[],int key);
        void display();
        void max_heapify(int arr[],int i);
        void building_maxheap(int arr[]);
        int maximum(int arr[]);
        int extract_max(int arr[]);
        void increase_key(int arr[], int i);
        void insert(int key);

        heap(int arraySize = 20)
      {
       n=0;
       arr=new int[arraySize];
       for(int i=0;i<arraySize;i++)
      {
       arr[i]=0;
         }
      }
     
  }; 

int heap::parent(int arr[],int i)            //function to get the parent of node of a tree
{
   return int((i-1)/2);
}


int heap::left(int i)              //function to get left child of node of a tree
{
  return 2*i+1;
}


int heap::right(int i)            //function to get right child of node of a tree
{
  return 2*i+2;
}

/*
 * To increase the key in Max Heap
 */
void heap::increase_key(int arr[], int i,int key)
{
  arr[i] = key;
  while((i>1) && (arr[parent(arr,i)] < arr[i])) 
{
    int temp=arr[i];
    arr[i]=arr[parent(arr,i)];
    arr[parent(arr,i)]=temp;
    i = parent(arr, i);
  }
}


/*
 * To insert key in Max Heap
 */
void heap::insert(int arr[],int key) 
{
  
     n[arr]=n[arr]+1;
     arr[n[arr]]=-1*INF;
     increase_key(arr,n[arr],key); 
}



/*
 * Max Heapify
 */
void heap::max_heapify(int arr[],int i)   
{
   int largest=i,temp;
   int l=left(i);
   int r=right(i);

 // finding largest among parent, left child and right child  

    if (l <= n  && arr[l] > arr[i])     
            largest=l;

    if (r <= n && arr[right] > arr[largest])
              largest=r;

     if (largest!=i)
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=arr[i];

    max_heapify(arr,largest);
}


/*
 * Building Max Heap
 */
void heap::building_maxheap(int arr[])
{
    int i;
    for(i = (n/2); i >= 1; i--)
    {
        max_heapify(arr,i);
    }
}


/*
 * To get Maximum key value from the Heap
 */
int heap::maximum(int arr[]) {
  return arr[1];
}

/*
 * Extract Maximum 
 */
int heap::extract_max(int arr[]) 
{
   if(n[arr]<1)
  {
   cout<<"Heap Underflow!!";
  }

  else
 {
  int max = arr[1];
  arr[1] = arr[n];
   n--;
  max_heapify(arr, 1);
  return max;
  }
}


/*
 * Display Heap
 */
void heap::display() 
{
  int i;
  for(i=1; i<=n; i++) 
{
    cout<<arr[i];
  }
    cout<<"\n";
}


int main() 
{   
    int choice,key,i;
    int arr[arraySize];
    heap h;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on Heap"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Increase the key value"<<endl;
        cout<<"2.Insert the Element"<<endl;
        cout<<"3.Return Maximum value"<<endl;
        cout<<"4.Extract Maximum Value"<<endl;
        cout<<"5.Display the Heap"<<endl;
        cout<<"6.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
         case 1:
            cout<<"Enter the index at which you want to increase the key: ";
            cin>>i;
            cout<<"Enter by how much the key value to be increased: ";
            cin>>key;
            h.increase_key(arr,i,key);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the key value to be inserted : ";
	    cin>>key;
            h.insert(arr,key);
            cout<<endl;
            break;
        case 3:
            h.maximum(arr);
            cout<<endl;
            break;
	case 4:
            h.extract_max(arr);
            cout<<endl;
            break;
       
         case 5:
            cout<<"Displaying the Heap: "<<endl;
            h.display();
            cout<<endl;
            break;
	case 6:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
            break;
       }
  }
      getch();
      return 0;
}

