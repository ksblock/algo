#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N+1);
    for(int i=0;i<N;i++)
        cin >> A[i];

    vector<int> dp(N+1);

    int ans = A[0];
    for(int i=0;i<N;i++)
    {
        dp[i] = A[i];
        for(int j=0;j<i;j++)
        {
            if(A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + A[i]);
        }
        ans = max(ans, dp[i]);
    }
    
    cout << ans << endl;
}