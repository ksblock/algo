#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int K, N;
    cin >> N >> K;

    queue <int> q;
    vector <int> v;

    for(int i=1;i<=N;i++)
        q.push(i);
    
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<K-1;j++)
        {
            int front = q.front();
            q.pop();
            q.push(front);
        }

        int front = q.front();
        q.pop();
        v.push_back(front);
    }

    cout << "<";
    for(int i=0;i<N-1;i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[N-1] << ">";
    
}
