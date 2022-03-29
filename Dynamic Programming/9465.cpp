#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        int in[2][100010]={0};
		int dp[2][100010]={0};

		for(int i=0;i<2;i++)
		{
			for(int j=2;j<=N+1;j++)
			{
				scanf("%d",&in[i][j]);
			}
		}
		
		for(int i=2;i<=N+1;i++)
		{
			dp[0][i]=max(max(dp[0][i-1],dp[1][i-1]+in[0][i]),dp[1][i-2]+in[0][i]);
			dp[1][i]=max(max(dp[1][i-1],dp[0][i-1]+in[1][i]),dp[0][i-2]+in[1][i]);
		}
		printf("%d\n",max(dp[0][N+1],dp[1][N+1]));
    }
}