#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int C, N;
    cin >> C >> N;

    vector<int> cost(N+1);
    vector<int> person(N+1);
    vector<int> dp(100001);

    for(int i=0;i<N;i++)
        cin >> cost[i] >> person[i];

    for(int i=0;i<=100001;i++)
        dp[i] = 0;

    for (int i = 1; i <= 100000; i++) 
    {
		for (int j = 0; j < N; j++) 
        {
			if (i % cost[j] == 0) 
            {
				dp[i] = max(dp[i], i * person[j] / cost[j]);
			}
			if (i >= cost[j]) 
            {
				dp[i] = max(dp[i], dp[i-cost[j]] + person[j]);
			}
		}
		if (C <= dp[i]) 
        {
			cout << i;
            break;
		}
	}
}