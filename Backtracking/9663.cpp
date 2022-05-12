#include<iostream>
#include<vector>
using namespace std;

int N, ans;
int board[16][16];

bool check(int x, int y)
{
    for(int i = 0; i<N;i++)
        if(board[x][i] == 1 || board[i][y] == 1)
            return false;

    for(int i=x, j=y;i>=0 && j>=0;i--,j--)
        if(board[i][j] == 1)
            return false;
    
    for(int i=x, j=y;i>=0 && j<N;i--,j++)
        if(board[i][j] == 1)
            return false;
    
    return true;
}

void back(int idx)
{
    if(idx == N)
    {
        ans++;
        return;
    }

    for(int i=0;i<N;i++)
        if(check(idx,i) == true)
        {
            board[idx][i] = 1;
            back(idx + 1);
            board[idx][i] = 0;
        }
}

int main()
{
    cin >> N;

    back(0);

    cout << ans;

}