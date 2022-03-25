#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> stair(N+1);
    vector<int> v(N+1);

    stair[0] = 0;
    for(int i=1;i<=N;i++)
        cin >> stair[i];
    
    v[1] = stair[1];
    v[2] = stair[1] + stair[2];

    for(int i=3;i<=N;i++)
        v[i] = max(v[i-2] + stair[i], v[i-3] + stair[i-1] + stair[i]);

    cout << v[N] << endl;
}