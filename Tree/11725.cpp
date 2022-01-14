#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int parent[100001];
int check[100001];
vector<int> tree[100001];

void dfs(int x)
{
    check[x] = 1;

    for(int i=0;i<tree[x].size();i++)
    {
        int next = tree[x][i];
        if(check[next] == 0)
        {
            parent[next] = x;
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int a,b;
    for(int i=0;i<N-1;i++)
    {
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1);

    for(int i=2;i<=N;i++)
        cout << parent[i] << endl;
}