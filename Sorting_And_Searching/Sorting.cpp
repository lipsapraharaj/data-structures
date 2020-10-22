#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;

template <class T> 
class sort
{
    private:
       T array[size];
       T i,j,k,count=0;
    public:
        void swap(T,T);   
        void bubblesort(T,T);
        void insertsort(T,T);
        void selectionSort(T,T);
        
};

/*
 * Swap function
 */

template <class T>
void sort<T>::swap(T &a,T &b)
{
T c=a;
a=b;
b=c;
}

/*
 * Bubble Sorting
 */

template <class T>
void sort<T>::bubblesort(T array[], T size)
{
for(i=0;i<size;i++)
{
for(j=0,count=0;j<(size-1);j++)
if(a[j]>a[j+1])
{
swap(a[j], a[j+1]);
count++;
}
if(i<(size-1))
{
cout<<"The no. of comparsions for "<<i+1<<"iterations are:"<<count;
cout<<"\nThe intermediate array at stage "<<i+1<<":";
for(k=0;k<size;k++)
cout<<a[k]<<" ";
}
}
}

/*
 * Insertion Sorting
 */

template <class T>
void sort<T>::insertsort(T array[], T size)
{
   T temp,count=0;
for(i=1;i<size;i++)
{
temp=array[i];
j=i-1;
while(temp<array[j] && j>=0)
{
array[j+1]=array[j];
j--;
count++;
}
array[j+1]=temp;
cout<<"The no. of comparsions for "<<i+1<<"iteration :"<<count;
cout<<"\nThe intermediate array at stage "<<i<<";";
for(k=0;k<size;k++)
cout<<array[k]<<" ";
count=0;
}
}

/*
 * Selection Sorting
 */

template <class T>
int sort<T>::selectionSort(int array[], int size)
{
    T small, iterCompCount;
    cout << "Array: ";
    for (k = 0; k < size; k++)
        cout << array[k] << " ";
    cout << endl;
    for (i = 0; i < size; i++)
    {
        iterCompCount = 0;
        small = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[small])
            {
                small = j;
            }
            count++;
            iterCompCount++;
        }
        int temp = array[i];
        array[i] = array[small];
        array[small] = temp;
        cout << "Comparisons Made in Pass " << i + 1 << ": " 
             << iterCompCount << endl;
        cout << "After Pass " << i + 1 << ": ";
        for (k = 0; k < size; k++)
            cout << array[k] << " ";
        cout << endl;
    }
    return count;
}



int main()
{
   int choice,size,array[size],i;
   sort<int> s;

 while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Menu For Performing Sortings"<<endl;
        cout<<endl<<"----------------------------"<<endl;         
        cout<<"1.Perform Bubble Sort"<<endl;
        cout<<"2.Perform Insertion Sort"<<endl;
        cout<<"3.Perform Selection Sort"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the size of array: ";
            cin>>size;
            cout<<"Enter the array :";
            for(i=0;i<size;i++)
            cin>>arr[i];
            s.bubblesort(array,size);
            cout<<"\nBubble Sorted Array: ";
            for(i=0;i<size;i++)
            cout<<array[i]<<" ";
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the size of array: ";
            cin>>size;
            cout<<"Enter the array :";
            for(i=0;i<size;i++)
            cin>>arr[i];
            s.insertsort(array,size);
            cout<<"\nInsertion Sorted Array: ";
            for(i=0;i<size;i++)
            cout<<array[i]<<" ";
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the size of array: ";
            cin>>size;
            cout<<"Enter the array :";
            for(i=0;i<size;i++)
            cin>>arr[i];
            s.selectionSort(array,size);
            cout<<"\nSelection Sorted Array: ";
            for(i=0;i<size;i++)
            cout<<array[i]<<" ";
            cout<<endl;
            break;
         case 4:
            exit(1);
            break;
        default:
            cout<<"Wrong choice"<<endl;
      }
    }
    return 0;
}






