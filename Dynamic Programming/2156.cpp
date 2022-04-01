#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> grape(N+1);
    vector<int> dp(N+1);

    for(int i=1;i<=N;i++)
        cin >> grape[i];

    dp[1] = grape[1];
    dp[2] = grape[1] + grape[2];

    for(int i=3;i<=N;i++)
    {
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], dp[i-3] + grape[i-1] + grape[i]);
        dp[i] = max(dp[i], dp[i-2] + grape[i]);
    }

    cout << dp[N] << endl;
}