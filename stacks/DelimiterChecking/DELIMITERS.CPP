#include <iostream>
#include <conio.h>
#include <stack.h>

using namespace std;

void deli_match();

int main()
{
    int t;
    cout << "Enter the number of cases for which you want to check:";
    cin >> t;

    for (int i = 0; i < t; i++) {
        //calling of function for checking of brackets
        deli_match();
    }

    return 0;
}

void deli_match()
{
    stack<char> a;
    string s;
    cout << "Enter the expression";
    cin >> s;

    int flag = 0; //flag is an arbitrary variable

    for (int i=0; i<s.length(); i++)
    //for length of the string calculated by number of letters
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            //push function to enter terms in a stack
            a.push(s[i]);
            flag = 1;
        }
        if (!a.empty()) {
            if (s[i] == '}') {
                if (a.top() == '{')
                // top of the stack
                {
                    a.pop();
                    //pop function to delete terms from the top of array
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']') {
                if (a.top() == '[') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')') {
                if (a.top() == '(') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }

    if ((a.empty()) && (flag == 1))
        cout << "YES...The delimiters matched"<< endl;
    else
        cout << "NO...The delimiters didn't matched"<< endl;
}
