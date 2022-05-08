#include<iostream>
#include<vector>
using namespace std;

int M, N;
vector<vector<int>> board;

long long back(int x, int y)
{
    if(x == N && y == M)
    {
        if(board[x-1][y-1] == 0 || board[x-1][y] == 0 || board[x][y-1] == 0)
            return 2;
        else 
            return 1;
    }

    long long re = 0;
    if(board[x-1][y-1] == 0 || board[x-1][y] == 0 || board[x][y-1] == 0)
    {
        board[x][y] = 1;
        if(y == M)
            re += back(x+1,1);
        else
            re += back(x, y+1);
        board[x][y] = 0;
    }

    if(y == M)
        re += back(x+1,1);
    else
        re += back(x, y+1);

    

    return re;
}

int main()
{
    cin >> N >> M;

    for(int i=0;i<N+1;i++)
    {
        vector<int> v(M+1);

        board.push_back(v);
    }

    long long ans = back(1,1);
    cout << ans;
}