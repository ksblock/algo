#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> egg;
int N, ans = 0;

void back(int idx)
{
    if(idx == N)
    {
        int re = 0;
        for(int i=0;i<N;i++)
            if(egg[i].first <= 0)
                re++;
        ans = max(ans, re);
        return;
    }

    if(egg[idx].first <= 0)
        back(idx+1);
    else
    {
        int flag = 0;
        for(int i=0;i<N;i++)
        {
            if(idx == i || egg[i].first <= 0)
                continue;
            
            flag = 1;

            egg[idx].first -= egg[i].second;
            egg[i].first -= egg[idx].second;

            back(idx+1);

            egg[idx].first += egg[i].second;
            egg[i].first += egg[idx].second;
        }
        if(flag == 0)
            back(N);
    }
}

int main()
{
    cin >> N;

    for(int i=0;i<N;i++)
    {
        int a, b;
        cin >> a >> b;
        egg.push_back(make_pair(a,b));
    }

    back(0);
    cout << ans;
}
