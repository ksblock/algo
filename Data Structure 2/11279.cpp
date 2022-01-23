#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> pq;

    int N;
    cin >> N;

    while(N--)
    {
        int query;
        cin >> query;

        if(query == 0)
        {
            if(pq.size() == 0)
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(query);
        }
    }
}