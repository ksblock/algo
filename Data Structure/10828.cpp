#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int N, data, top;
    string command;
    stack<int> st;

    cin >> N;

    for(int i=0;i<N;i++)
    {
        cin >> command;

        if(command == "push")
        {
            cin >> data;
            st.push(data); 
        }
        else if(command == "pop")
        {
            if(st.empty())
                cout <<  -1 << endl;
            else
            {
                top = st.top();
                st.pop();
                cout << top << endl;
            }
        }
        else if(command == "size")
        {
            cout << st.size() << endl;
        }
        else if(command == "empty")
        {
            if(st.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            if(st.empty())
                cout << -1 << endl;
            else
                cout << st.top() << endl;
        }
    }
}