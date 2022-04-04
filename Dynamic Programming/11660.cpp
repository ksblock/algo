#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> board;
    vector<vector<int>> dp;

    for(int i=0;i<=N;i++)
    {
        vector<int> temp(N+1);
        board.push_back(temp);
        dp.push_back(temp);
    } 

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin >> board[i][j];



    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + board[i][j] - dp[i-1][j-1];

    for(int i=0;i<M;i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];

        cout << ans << "\n";
    }
}