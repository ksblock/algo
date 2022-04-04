#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> dp;
    for(int i=0;i<=9;i++)
    {
        vector<int> temp(N);
        dp.push_back(temp);
    }
    
    dp[0][0] = 0;
    for(int i=1;i<=9;i++)
        dp[i][0] = 1;
    
    for(int i=1;i<N;i++)
    {
        dp[0][i] = dp[1][i-1];
        for(int j=1;j<=8;j++)
            dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1]) % 1000000000;
        dp[9][i] = dp[8][i-1];
    }

    int ans = 0;
    for(int i=0;i<=9;i++)
        ans = (ans + dp[i][N-1]) % 1000000000;

    cout << ans << endl;
}