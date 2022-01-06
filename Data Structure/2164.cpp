#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int N, data;
    queue<int> q;

    cin >> N;

    for(int i=1;i<=N;i++)
        q.push(i);

    for(int i=0;i<N-2;i++)
    {
        q.pop();
        data = q.front();
        q.pop();
        q.push(data);
    }

    if(N != 1)
        q.pop();
    cout << q.front() << endl;

}