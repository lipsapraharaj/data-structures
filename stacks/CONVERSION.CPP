#include<iostream>
#include<string.h>
using namespace std;

const int Max=255;
class Stack
{
private:
    char element[Max];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    bool isFull()
    {
        if(top>=(Max-1)) 
        return true;
        else 
        return false;
    }
    bool isEmpty()
    {
        if(top==-1)
          return true;
        else
         return false;
    }
    bool push(char x)
    {
        if(!isFull())
        {
            top++;
            element[top]=x;
            return true;
        }
        else
        {
            cout<<"Stack is full"<<endl;
            return false;
        }
    }
    bool pop(char &x)
    {
        if(!isEmpty())
        {
            x=element[top--];
            return true;
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return false;
        }
    }
    char topel()
    {
        if(!isEmpty())
        {
            return element[top];
        }
        else
        {
            cout<<"Stack is empty"<<endl;
            return ' ';
        }
    }
};


class Converter
{
public:
    Converter(){}
    bool isOperator(char x)
    {
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')') 
          return true;
        else 
          return false;
    }
    bool isOperand(char x)
    {
        if(x>='0'&& x<='9') 
          return true;
        else 
          return false;
    }
    int priority(char x)
    {
        if(x=='+'||x=='-') 
          return 1;
        else if(x=='*'||x=='/') 
          return 2;
        else if(x=='^')
          return 3;
        else 
         return 0;
    }
    char ToPostfix(char infix[])
    {
        Stack stack1;
        char res[20];
        int resindex=0;
        for(int i=0;i<strlen(infix);i++)
        {
            if(isOperator(infix[i]))
            {
                if(infix[i]=='(')
                {
                    stack1.push(infix[i]);
                }
                else if(infix[i]==')')
                {
                    while(stack1.topel()!='(')
                    {
                        stack1.pop(res[resindex++]);
                    }
                    stack1.pop(res[resindex]);
                }
                else 
                {
                    while(priority(infix[i])<=priority(stack1.topel()))
                    {
                        stack1.pop(res[resindex++]);
                    }
                    stack1.push(infix[i]);
                }
            }
            else if(isOperand(infix[i]))
            {
                res[resindex++]=infix[i];
            }
        }
        while(!stack1.isEmpty())
        {
            stack1.pop(res[resindex++]);
        }
        res[resindex]='\0';
        return res;
    }
    char ToPrefix(char infix[])
    {
        char res[20];
        strcpy(res,strrev(infix));
        for(int i=0;i<strlen(res);i++)
        {
            if(res[i]=='(') 
            {
                res[i]=')';
            }
            else if(res[i]==')')
            {
                res[i]='(';
            }
             else if(res[i]=='[')
                res[i]=']';
             }
             
              else if(res[i]=='{')
              res[i]='}';
        }
        strcpy(res,ToPostfix(res));
        strcpy(res,strrev(res));
        return res;
    }
};
int main()
{
    Converter c;
    char infix[20];
    cout<<"Enter infix expression: ";
    cin>>infix;
    cout<<endl<<"Prefix: "<<c.ToPrefix(infix)<<endl;
    cout<<"Postfix: "<<c.ToPostfix(infix)<<endl;
    return 0;
}