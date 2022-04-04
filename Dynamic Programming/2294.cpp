#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> coin(N);
    for(int i=0;i<N;i++)
        cin >> coin[i];

    vector<int> dp(K+1);

    for(int i=0;i<N;i++)
    {
        int now = coin[i];
        for(int j=0;j<K;j++)
        {
            if(j + now > K)
                break;
            if(dp[j] == 0 && j != 0)
                continue;

            if(dp[j + now] == 0)
                dp[j + now] = dp[j] + 1;
            else
                dp[j + now] = min(dp[j+now], dp[j] + 1);
        }
    }

    if(dp[K] == 0)
        cout << -1 << endl;
    else
        cout << dp[K] << endl;
}