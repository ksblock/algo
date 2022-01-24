#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        map<int, int> m;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int, vector<int>, less<int>> max_heap;

        int K;
        cin >> K;

        while(K--)
        {
            int n;
            char op;

            cin >> op >> n;
            
            if(op =='D')
            {
                if(n == 1)
                {
                    while(!max_heap.empty() && m[max_heap.top()] == 0)
                        max_heap.pop();
                    
                    if(max_heap.empty())
                        continue;
                    else
                    {
                        m[max_heap.top()]--;
                        max_heap.pop();
                    }
                }
                else
                {
                    while(!min_heap.empty() && m[min_heap.top()] == 0)
                        min_heap.pop();
                    
                    if(min_heap.empty())
                        continue;
                    else
                    {
                        m[min_heap.top()]--;
                        min_heap.pop();
                    }
                }
            }
            else
            {
                max_heap.push(n);
                min_heap.push(n);
                m[n]++;
            }

            while(!max_heap.empty() && m[max_heap.top()] == 0)
                max_heap.pop();
            while(!min_heap.empty() && m[min_heap.top()] == 0)
                min_heap.pop();
        }

        if(max_heap.empty())
            cout << "EMPTY\n";
        else
            cout << max_heap.top() << " " << min_heap.top() << "\n";
    }
}