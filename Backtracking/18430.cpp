#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, ans = 0;
vector<vector<int>> input;
vector<vector<int>> visit;

int check(int x1, int y1, int x2, int y2, int x3, int y3)
{    
    if(x2 < 0 || y2 < 0 || x3 < 0 || y3 < 0)
        return -1;
    if(x2 >= N || y2 >= M || x3 >= N || y3 >= M)
        return -1;
    if(visit[x1][y1] == 1 || visit[x2][y2] == 1 || visit[x3][y3] == 1)
        return -1;

    int re = input[x1][y1] * 2 + input[x2][y2] + input[x3][y3];
    return re;
}

void back(int x, int y, int sum)
{
    if(x == N)
    {
        ans = max(ans, sum);
        return;
    }

    int intensity = check(x,y, x-1, y, x, y-1);
    if(intensity != -1)
    {
        visit[x][y] = 1;
        visit[x-1][y] = 1;
        visit[x][y-1] = 1;
        if(y == M - 1)
            back(x+1, 0, sum + intensity);
        else
            back(x, y+1, sum + intensity);
        visit[x][y] = 0;
        visit[x-1][y] = 0;
        visit[x][y-1] = 0;
    }

    intensity = check(x,y, x-1, y, x, y+1);
    if(intensity != -1)
    {
        visit[x][y] = 1;
        visit[x-1][y] = 1;
        visit[x][y+1] = 1;
        if(y == M - 1)
            back(x+1, 0, sum + intensity);
        else
            back(x, y+1, sum + intensity);
        visit[x][y] = 0;
        visit[x-1][y] = 0;
        visit[x][y+1] = 0;
    }

    intensity = check(x,y, x+1, y, x, y-1);
    if(intensity != -1)
    {
        visit[x][y] = 1;
        visit[x+1][y] = 1;
        visit[x][y-1] = 1;
        if(y == M - 1)
            back(x+1, 0, sum + intensity);
        else
            back(x, y+1, sum + intensity);
        visit[x][y] = 0;
        visit[x+1][y] = 0;
        visit[x][y-1] = 0;
    }

    intensity = check(x,y, x+1, y, x, y+1);
    if(intensity != -1)
    {
        visit[x][y] = 1;
        visit[x+1][y] = 1;
        visit[x][y+1] = 1;
        if(y == M - 1)
            back(x+1, 0, sum + intensity);
        else
            back(x, y+1, sum + intensity);
        visit[x][y] = 0;
        visit[x+1][y] = 0;
        visit[x][y+1] = 0;
    }

    if(y == M - 1)
            back(x+1, 0, sum);
        else
            back(x, y+1, sum);
}

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {   
        int num;
        vector<int> temp(M);
        visit.push_back(temp);

        for(int j=0;j<M;j++)
            cin >> temp[j];
        input.push_back(temp);
    }

    back(0,0,0);

    cout << ans;
}
