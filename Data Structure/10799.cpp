#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    int ans = 0;
    string bracket;
    stack<char> st;

    cin >> bracket;

    for(int i=0;i<bracket.length();i++)
    {
        if(bracket[i] =='(' && bracket[i+1] == ')')
        {
            ans += st.size();
            i++;
        }
        else if(bracket[i] == '(')
        {
            ans++;
            st.push('(');
        }
        else if(bracket[i] == ')')
        {
            st.pop();
        }
    }

    cout << ans << endl;
}