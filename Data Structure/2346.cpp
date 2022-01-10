#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int N, data;
    int index, move;
    deque<pair<int,int>> dq;

    cin >> N;

    for(int i=1;i<=N;i++)
    {
        cin >> data;
        dq.push_back(make_pair(i,data));
    }

    cout << dq.front().first << " ";
    move = dq.front().second;
    dq.pop_front();

    while(!dq.empty())
    {    
        if(move > 0)
        {
            for(int i = 0; i< move - 1; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cout << dq.front().first << " ";
            move = dq.front().second;
            dq.pop_front();
        }   
        else
        {
            move *= -1;
            for(int i = 0;i < move - 1; i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back().first << " ";
            move = dq.back().second;
            dq.pop_back();
        }
    }
}