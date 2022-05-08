#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, ans = 999999999;
vector<int> visit;
vector<vector<int>> input;

void back(int st, int now, int dist, int num)
{
    if(num == N)
    {
        if(input[now][st] != 0)
            ans = min(ans, dist + input[now][st]);
        return;
    }

    for(int i=0;i<N;i++)
    {
        if(input[now][i] == 0 || visit[i] == 1)
            continue;

        visit[i] = 1;
        back(st, i, dist + input[now][i], num + 1);
        visit[i] = 0;
    }
}

int main()
{
    cin >> N;

    for(int i=0;i<N;i++)
    {
        vector<int> a(N);
        input.push_back(a);
        visit.push_back(0);

        for(int j=0;j<N;j++)
            cin >> input[i][j];
    }

    for(int i=0;i<N;i++)
    {
        visit[i] = 1;
        back(i, i, 0, 1);
        visit[i] = 0;
    }

    cout << ans;
}