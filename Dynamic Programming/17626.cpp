#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> DP(N+1);

    DP[0] = 0;
    DP[1] = 1;
    for(int i=2;i<=N;i++)
    {
        DP[i] = 9999;
        for(int j=1;j*j<=i;j++)
        {
            DP[i] = min(DP[i], DP[i - j*j] + 1);
        }
    }

    cout << DP[N];
}