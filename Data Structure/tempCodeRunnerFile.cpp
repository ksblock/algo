#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int N, data, prev = 0;
    bool check = true;

    cin >> N;

    stack<int> st;
    vector<char> ans;

    while(N--)
    {
        cin >> data;
        if(prev < data)
        {
            while(prev<=data)
            {
                st.push(prev);
                ans.push_back('+');
                prev++;
            }
            ans.push_back('-');
            st.pop();
        }
        else
        {
            if(st.top() == data)
            {
                st.pop();
                ans.push_back('-');
            }
            else
            {
                check = false;
                break;
            }
        }
    }

    if(check == true)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << endl;
    }
    else
        cout << "NO" << endl;
}