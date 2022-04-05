#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> jump(N);
    vector<int> big_jump(N);
    int super_jump;

    for(int i=0;i<N-1;i++)
        cin >> jump[i] >> big_jump[i];
    cin >> super_jump;

    if(N == 1)
    {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dp;
    for(int i=0;i<N+1;i++)
    {
        vector<int> v;
        v.push_back(999999999);
        v.push_back(999999999);

        dp.push_back(v);
    }

    dp[1][0] = 0;
    dp[1][1] = 0;

    for (int i = 1; i<=N-1 ; ++i) {
        if (i + 1 <= N) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + jump[i-1]);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + jump[i-1]);
        }

        if (i + 2 <= N) {
            dp[i+2][0] = min(dp[i+2][0], dp[i][0] + big_jump[i-1]);
            dp[i+2][1] = min(dp[i+2][1], dp[i][1] + big_jump[i-1]);
        }

        if (i + 3 <= N){
            dp[i+3][1] = min(dp[i+3][1], dp[i][0] + super_jump);
        }
    }

    cout << min(dp[N][0], dp[N][1]);
}