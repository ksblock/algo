#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> coin(N+1);
    vector<int> dp(K+1);
    dp[0] = 1;

    for(int i=1;i<=N;i++)
        cin >> coin[i];

    for(int i=1;i<=N;i++)
        for(int j=0;j + coin[i] <= K;j++)
                dp[j + coin[i]] += dp[j];
    
    cout << dp[K];
}