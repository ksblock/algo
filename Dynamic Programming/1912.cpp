#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N+1);
    vector<int> dp(N+1);
    for(int i=1;i<=N;i++)
        cin >> v[i];

    int ans = -9999;

    for(int i=1;i<=N;i++)
    {
        if(dp[i - 1] <= 0)
            dp[i] = v[i];
        else
            dp[i] = dp[i-1] + v[i];

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}