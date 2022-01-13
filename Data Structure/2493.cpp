#include<iostream>
#include<stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, data, top;
    stack<pair<int,int>> st;
    st.push(make_pair(10000000000, 0));

    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> data;

        while(!st.empty())
        {
            top = st.top().first;
            
            if(top > data)
            {
                cout << st.top().second << " ";
                break;
            }
            else
            {
                st.pop();
            }
        }
        st.push(make_pair(data,i));
    }
}