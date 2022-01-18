#include<iostream>
#include<vector>
using namespace std;

int N, R;
int giga, giga_length, branch;
int visit[200001];
vector<pair<int,int>> v[200001];
void find_giga(int now, int dist);
void max(int now, int dist);

int main()
{

    cin >> N >> R;

    if(N==1)
    {
        cout << 0 << " " << 0;
        return 0;
    }

    int a,b,d;
    for(int i=0;i<N-1;i++)
    {
        cin >> a >> b >> d;
        v[a].push_back(make_pair(b,d));
        v[b].push_back(make_pair(a,d));
    }

    visit[R] = 1;
    find_giga(R, 0);
    max(giga, 0);

    cout << giga_length << " " << branch << endl;
}

void find_giga(int now, int dist)
{
    if(v[now].size() > 2)
    {
        giga = now;
        giga_length = dist;
        return;
    }

    if(now == R && v[now].size() == 2)
    {
        giga = now;
        giga_length = dist;
        return;
    }

    if(now != R && v[now].size() == 1)
    {
        giga = now;
        giga_length = dist;
        return;
    }

    for(int i=0;i<v[now].size();i++)
    {
        int next = v[now][i].first;
        if(visit[next] == 0)
        {
            visit[next] = 1;
            find_giga(next, dist + v[now][i].second);
        }
    }
}

void max(int now, int dist)
{
    if(v[now].size() == 1)
    {
        if(branch < dist)
            branch = dist;
        return;
    }

    for(int i=0;i<v[now].size();i++)
    {
        int next = v[now][i].first;
        if(visit[next] == 0)
        {
            visit[next] = 1;
            max(next, dist + v[now][i].second);
        }
    }
}