#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, data, prev = 1;
    bool check = true;

    cin >> N;

    stack<int> st;
    vector<char> ans;

    while(N--)
    {
        cin >> data;
        if(prev <= data)
        {
            while(prev<=data)
            {
                st.push(prev);
                ans.push_back('+');
                prev++;
            }
        }

        if(data < prev)
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
            cout << ans[i] << "\n";
    }
    else
        cout << "NO" << endl;
}