#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

//Node Class
class Node
{
public:
    int data;
    int Node* next;
    //constructor
    Node(int data = 0, Node* next= 0)
    {
        this->data = data;
        this->nextNode = next;
    }
    //destructor
    ~Node()
    {
        cout<<"Destroying Node; DATA = <<"<<this->data<<"\n";
    }
};
class OrderedLinkedList
{
private:
    int totalNodes;
    Node *head,*tail,*temp;
public:
    
    OrderedLinkedList()
    {
        head = tail = temp = 0;
        totalNodes = 0;
    }
    ~OrderedLinkedList()
    {
        temp = head;
        Node *nextptr = 0;
        cout<<"Destroying The List\n";
        while(temp != 0)
        {
            nextptr = temp->next;
            delete temp;
            temp = nexttr;
        }
        cout<<"Done.\n";
    }

    //insert function
    void insert()
    {
        temp = new Node();
        cout<<"Enter the Data : ";
        cin>>temp->data;
        if(head == 0)
        {
            head = tail = temp;
            totalNodes++; 
        }
        else if(head->data == temp->data || tail->data == temp->data)
        {
            return;
        }
        else if(head->data > temp->data)
        {
            temp->next= head;
            head = temp;
            totalNodes++;
        }
        else if(tail->data < temp->data)
        {
            tail->next= temp;
            tail = temp;
            totalNodes++;
        }
        else
        {
            Node *reqNode = head;
            while(reqNode->next->data < temp->data)
            {
                reqNode = reqNode->next;
            }
            if(reqNode->next->data == temp->data)
            {
                //the Node Already Exists
                return;
            }
            else
            {
                if(reqNode->nextNode == tail)
                {
                    tail = temp;
                }
                temp->next= reqNode->next;
                reqNode->next= temp;
                totalNodes++;
            }
            
        }
        temp = 0;
        
    }


    //delete function
    void delete()
    {
        int loc;
        cout<<"Enter the Location : "; 
        cin>>loc;
        if(totalNodes > 0)
        {
            if(loc < 0 || loc > totalNodes)
            {
                cout<<"INVALID\n";
                cout<<"Press Enter to Continue ";
                getch();
            }
            else if(loc == 1)
            {
                temp = head;
                if(totalNodes == 1)
                {
                    head = tail = 0;
                }
                else
                {
                    head = head->next;                    
                }
                delete temp;
                temp = 0;
                totalNodes--;
            }
            else
            {
                int counter = 1;
                temp = head;
                while(counter != (loc-1))
                {
                    temp = temp->next;
                    counter++;
                }
                Node *reqNode = temp->next;
                temp->next= reqNode->next;
                if(reqNode == tail)
                {
                    temp->nextNode = 0;
                    tail = temp;
                }
                delete requiredNode;
                temp = requiredNode = 0;
                totalNodes--;
            }
            
        }
    }
    //traverse function
    void traverse()
    {
        if(totalNodes > 0)
        {
            temp = head;
            while(temp != 0)
            {
                cout<<temp->data<<" ";
                temp = temp->nextNode;
            }
            cout<<"\n";
            temp = 0;
        }
        else
        {
            cout<<"EMPTY\n";
        }
        
    }
};

void MergeSort(node *head)
{
	node *first = new node;
	node *second = new node;
	node *temp = new node;
	first = *head;
	temp = *head;
 
	// Return if list have less than two nodes.
	if(first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		// Break the list into two half as first and second as head of list.
		while(first->next != NULL)
		{
			first = first->next;
			if(first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}
 
	// Implementing divide and conquer approach.
	MergeSort(&first);
	MergeSort(&second);
 
	// Merge the two part of the list into a sorted one.      
	*head = Merge(first, second);
}
 

int main()
{
    OrderedLinkedList oll = new OrderedLinkedList();
    int choice,n,i,num;
    Node *head = new Node;
     Node *tail = new node;
	head = NULL;
	tail = NULL;
    char flag = 'y';
    do
    {
        cout<<"\n";
        cout<<setw(20)<<setfill(' ')<<"ORDERED LINKED LIST\n";
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"LIST  : "; A->traverse();
        cout<<setw(30)<<setfill('-')<<"\n";
        cout<<"1. Insert \n"
            <<"2. Delete \n"
            <<"3.Merge   \n"
            <<"4.. Exit\n";
        cout<<"Enter What you want to do ? : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            oll.insert();
            break;
        case 2:
            oll.delete();
            break;
        case 3:
             oll.merge();
             cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
 
	// Create linked list.
	for(int i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>num;
 
		tail = AddToList(tail, num);
		if(head == NULL)
			head = tail;
	}
 
	// Send reference of head into MergeSort().
	MergeSort(&head);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
 
	while(head != NULL) 
	{
		cout<<".."<<head->data;
		head=head->next;
	}
	return 0;	
}
             break;
        case 4:
            flag = 'n';
            break;
        default:
            break;
        }
        system("CLS");

    }while(flag != 'n');







	

