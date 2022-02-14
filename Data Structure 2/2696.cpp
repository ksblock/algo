#include<iostream>
#include<vector>
#include<queue>
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
        int M;
        vector<int> ans;
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>>min_heap;

        cin >> M;

        for(int i=1;i<=M;i++)
        {
            int num;
            cin >> num;

            if(max_heap.size() == min_heap.size())
                max_heap.push(num);
            else
                min_heap.push(num);

            if(!max_heap.empty() && !min_heap.empty() && min_heap.top() < max_heap.top())
            {
                int toMin = max_heap.top();
                int toMax = min_heap.top();

                max_heap.pop();
                min_heap.pop();
                
                max_heap.push(toMax);
                min_heap.push(toMin);
            }

            if(i%2==1)
                ans.push_back(max_heap.top());
        }

        cout << ans.size() << endl;
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}