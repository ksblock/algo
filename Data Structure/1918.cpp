#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string input;
    string output = "";
    stack<char> st;

    cin >> input;

    for(int i=0;i<input.length();i++)
    {
        if(input[i] == '+' || input[i] == '-')
        {
            while(!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.push(input[i]);
        }
        else if(input[i] == '*' || input[i] == '/')
        {
            while(!st.empty() && (st.top() == '*' || st.top() == '/'))
            {
                output += st.top();
                st.pop();
            }
            st.push(input[i]);
        }
        else if(input[i] == '(')
        {
            st.push('(');
        }
        else if(input[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else
            output += input[i];
    }

    while(!st.empty())
    {
        output += st.top();
        st.pop();
    }

    cout << output;
}