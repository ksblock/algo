#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int N;
    string PS;
    stack <char> st;
    cin >> N;

    while(N--)
    {
        cin >> PS;
        for(int i=0;i<PS.length();i++)
        {
            if(PS[i] == '(')
            {
                if(!st.empty() && st.top() == ')')
                        break;
                else
                    st.push('(');
            }
            else
            {
                if(st.empty())
                {
                    st.push(')');
                    break;
                }
                else
                    st.pop();
            }
        }

        if(st.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout <<"NO" << endl;

            while(!st.empty())
                st.pop();
        }
    }
}