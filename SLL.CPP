#include<iostream.h>
#include<conio.h>
class linkedlist
{
struct node
{
int data;
 node *next;
};
node *head,*tail,*temp;
public:
void add_node();
void display();
linkedlist()
{
head=NULL;
tail=NULL;
}
void add_node(int n)
{
node *temp=new node;
temp->data=n;
temp->next=NULL;
if(head==NULL)
{
head=temp;
tail=temp;
}
else
{
tail->next=temp;
tail=tail->next;
}
}
};
void display()
{
temp=head;
if(head==NULL)
cout<<"list is empty";
else
while(temp!=NULL)
{cout<<temp->data<<":";
temp=temp->next;
}
}
void main()
{ clrscr();
linkedlist l;
l.add_node(2);
l.add_node(4);
l.add_node(7);
l.add_node(9);
display();
getch();
}
