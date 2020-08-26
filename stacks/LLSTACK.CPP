#include<iostream>
#include<conio.h>
#include<process.h>
 
using namespace std;
 
struct Node
{
	int data;
	Node *next;
}*top=NULL,*p;
 
Node* newnode(int x)
{
	p=new Node;
	p->data=x;
	p->next=NULL;
	return(p);
}
 
void push(Node *q)
{
	if(top==NULL)
		top=q;
	else
	{
		q->next=top;
		top=q;
	}
}
 
void pop(){
	if(top==NULL){
		cout<<"Stack is empty!!";
	}
	else{
		cout<<"Deleted element is "<<top->data;
		p=top;
		top=top->next;
		delete(p);
	}
}
 
void display()
{
	Node *q;
	q=top;
 
	if(top==NULL){
		cout<<"Stack is empty!!";
	}
	else{
		while(q!=NULL)
		{
			cout<<q->data<<" ";
			q=q->next;
		}		
	}
}

void clear()
{
while(!this->isEmpty())
this->pop();
}
 
void topel()
{
if(top!=0)
cout<<top->data;
}


int main()
{
	int ch,x;
	Node *nptr;
	
	while(1)
	{
		cout<<"\n\n1.Push\n2.Pop\n3.Display\n4.Clear\n5.Top\n6.Exit";
		cout<<"\nEnter your choice(1-4):";
		cin>>ch;
		
		switch(ch){
	        case 1: 
                        cout<<"\nEnter data:";
	         	cin>>x;
			nptr=newnode(x);
			push(nptr);
			break;
			
			case 2: 
                         pop();
			 break;
					
			case 3: 
                         display();
		         break;
			
			case 4: 
                         clear();
                         break;
                        
                        case 5: 
                         topel();
                         break;

                        case 6:
                        exit(0);
			
			default: cout<<"\nWrong choice!!";
		}
	}
	
	return 0;
}