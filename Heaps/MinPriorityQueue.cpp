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
        void min_heapify(int arr[],int i);
        void building_minheap(int arr[]);
        int minimum(int arr[]);
        int extract_min(int arr[]);
        void derease_key(int arr[], int i);
        void insert(int key);
        void heap_sort(arr);


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
 * To decrease the key in Heap
 */
void heap::decrease_key(int arr[], int i,int key)
{
  arr[i] = key;
  while((i>1) && (arr[parent(arr,i)] > arr[i]))
{
    int temp=arr[i];
    arr[i]=arr[parent(arr,i)];
    arr[parent(arr,i)]=temp;
    i = parent(arr, i);
  }
}

/*
 * To insert key in Heap
 */
void heap::insert(int arr[],int key)
{
     n[arr]++;
     arr[n[arr]]=INF;
     decrease_key(arr,n[arr],key);
}

/*
 * Min Heapify
 */
void heap::min_heapify(int arr[],int i)
{
   int smallest=i,temp;
   int l=left(i);
   int r=right(i);

 // finding smallest among parent, left child and right child

    if (l <= n  && arr[l] < arr[i])
           {
             smallest=l;
            }
    else
      {
        smallest=i;
     }

    if (r <= n && arr[r] < arr[smallest])
     {
      smallest=r;
       }

     if (smallest!=i)
       {
        temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=arr[i];

    min_heapify(arr,smallest);
   }
}


/*
 * Building Min Heap
 */
void heap::building_minheap(int arr[])
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        min_heapify(arr,i);
    }
}

/*
 * To get Minimum key value from the Heap
 */
int heap::minimum(int arr[])
{
  return arr[1];
}


/*
 * Extract Minimum
 */
int heap::extract_min(int arr[])
{
  int min = arr[1];
  arr[1] = arr[n];
  n--;
  min_heapify(arr, 1);
  return min;
}

/*
 * Sorting the Heap
 */
void heap::heap_sort(int arr[])
{
        building_minheap(int arr[]);        
        int i, temp;
	for (i = n; i >= 2; i--)
	{
		// Storing minimum value at the end
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
                n[arr]--;

		min_heapify(arr,1);         // Building min heap of remaining element
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
    cout<<"Enter heap size: ";
    cin>>n;
    while (1)
    {
       cout<<"-----------------"<<endl;
        cout<<"Operations on Heap"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Decrease the key value"<<endl;
        cout<<"2.Insert the Element"<<endl;
        cout<<"3.Return Minimum value"<<endl;
        cout<<"4.Extract Minimum Value"<<endl;
        cout<<"5.Display the Heap"<<endl;
        cout<<"6.Sort the Heap"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
         case 1:
            cout<<"Enter the index at which you want to decrease the key: ";
            cin>>i;
            cout<<"Enter by how much the key value to be decreased: ";
            cin>>key;
            h.decrease_key(arr,i,key);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the key value to be inserted : ";
	    cin>>key;
            h.insert(arr,key);
            cout<<endl;
            break;
        case 3:
            h.minimum(arr);
            cout<<endl;
            break;
	case 4:
            h.extract_min(arr);
            cout<<endl;
            break;
       
         case 5:
            cout<<"Displaying the Heap: "<<endl;
            h.display();
            cout<<endl;
            break;
         case 6:
            h.heap_sort(arr);
            cout<<"\nSorted Heap: "<<endl;        // Printing the sorted heap 
	    h.display();
            break;
	case 7:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
            break;
       }
  }
      getch();
      return 0;
}



