#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[500001];

int count(int node, int parent)
{
    if(tree[node].size() == 1 && node != 1)
        return 1;

    int re = 0;
    for(int i=0;i<tree[node].size();i++)
    {
        if(tree[node][i]==parent)
            continue;
        re += count(tree[node][i], node);
    }
    return re;
}

int main()
{
    int N, W;
    int U, V;

    

    cin >> N >> W;
    for(int i=0;i<N-1;i++)
    {
        cin >> U >> V;
        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    int leaf = count(1, 0);
    double ans = (double) W / leaf;

    cout.precision(6);
    cout << fixed << ans << endl;
}