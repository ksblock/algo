#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> plus;
    priority_queue<int, vector<int>, less<int>> minus;

    for(int i=0;i<N;i++)
    {
        int x;
        cin >> x;

        if(x == 0)
        {
            if(plus.empty() && minus.empty())
            {
                cout << 0 << "\n";
            }
            else if(plus.empty() && !minus.empty())
            {
                cout << minus.top() << "\n";
                minus.pop();
            }
            else if(!plus.empty() && minus.empty())
            {
                cout << plus.top() << "\n";
                plus.pop();
            }
            else
            {
                int p_top = plus.top();
                int m_top = minus.top();
                if(p_top == -1 * m_top)
                {
                    cout << m_top << "\n";
                    minus.pop();
                }
                else if(p_top > -1 * m_top)
                {
                    cout << m_top << "\n";
                    minus.pop();
                }
                else
                {
                    cout << p_top << "\n";
                    plus.pop();
                }
            }

        }
        else if(x > 0)
        {
            plus.push(x);
        }
        else
        {
            minus.push(x);
        }
    }
}