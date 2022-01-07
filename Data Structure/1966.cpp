#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N,M,priority,ans = 1;
        queue<pair<int,int>> q;
        priority_queue<int> pq;

        cin >> N >> M;
        for(int i=0;i<N;i++)
        {
            cin >> priority;
            q.push(make_pair(i,priority));
            pq.push(priority);
        }

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();

            if(p.second == pq.top())
            {
                if(p.first == M)
                {
                    cout << ans << endl;
                    break;
                }
                pq.pop();
                ans++;
            }
            else
                q.push(p);
        }
    }
}