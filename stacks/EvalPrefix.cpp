#include <iostream>
#include<string>
#define MAX 10
using namespace std;

class Stack
{
	int arr[MAX];

 public:


     int top;
     void clear();
     bool isOperand(char);
     int eval_Prefix(string);

     Stack()
     {
     	top=-1;
     }

     void push(int a)
     {
     	if(top==MAX)
     		cout<<"\nStack is full";
     	else
     	    arr[++top] = a;
     }

     int pop()
     {
     	if(top!=-1)
     		return arr[top--];
     }


};

void Stack::clear()
{
top=-1;
}

bool Stack::isOperand(char c)
{
    // If the character is a digit then, it must be an operand
    return isdigit(c);
}

int Stack::eval_Prefix(string exprsn)
{
    Stack s1;

    for (int i = exprsn.size() - 1; i >= 0; i--)
{
        if (isOperand(exprsn[i]))
            s1.push(exprsn[i] - '0');

        else
        {
            int ch1 =s1.pop();
            int ch2 =s1.pop();

            switch (exprsn[i])
            {
            case '+':
                s1.push(ch1 + ch2);
                break;
            case '-':
                s1.push(ch1 - ch2);
                break;
            case '*':
                s1.push(ch1 * ch2);
                break;
            case '/':
                s1.push(ch1 / ch2);
                break;
            case '%':
                s1.push(ch1 % ch2);
                break;
            }
        }
    }

    return s1.pop();
}


int main()
{   Stack s1;
    string exprsn;
    cout<<"Enter the prefix expression: ";
    cin>>exprsn;
    cout << "The result after evaluation of Prefix expression= "<<s1.eval_Prefix(exprsn)<< endl;
    return 0;
}

