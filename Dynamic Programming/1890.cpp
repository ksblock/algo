#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> v;
    vector<vector<long long>> dp;
    
    for(int i=0;i<N;i++)
    {
        vector<int> temp_v(N);
        vector<long long> temp_dp(N);

        v.push_back(temp_v);
        dp.push_back(temp_dp);

        for(int j=0;j<N;j++)
        {
            cin >> v[i][j];
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            //cout << i << " " << j << " " << dp[i][j] << endl;
            if(v[i][j] == 0)
                continue;
            
            if(j + v[i][j] < N)
                dp[i][j + v[i][j]] += dp[i][j];
            if(i + v[i][j] < N)
                dp[i + v[i][j]][j] += dp[i][j]; 
        }
    }
    
    cout << dp[N-1][N-1] << endl;
}