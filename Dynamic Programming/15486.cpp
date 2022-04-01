#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> T(N+1);
    vector<int> P(N+1);
    vector<int> dp(N+2);

    for(int i=1;i<=N;i++)
    {
        dp[i] = 0;
        cin >> T[i] >> P[i];
    }

    dp[0] = 0;
    dp[N+1] = 0;

    for(int i=1;i<=N;i++)
    {
        dp[i] = max(dp[i], dp[i-1]);

        if(i+T[i] > N+1)
            continue;

        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
    }

    dp[N+1] = max(dp[N], dp[N+1]);

    cout << dp[N+1] << endl;
}