#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int idx;
    vector<pair<int,int>> edge; //node, dist 
};

Node node[10001];
bool out[10001]; // true leaf 아님 false leaf

int dfs(int now, int pre);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int parent, child, dist;
    
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        cin >> parent >> child >> dist;
        node[parent].edge.push_back(make_pair(child, dist));
        node[child].edge.push_back(make_pair(parent, dist));
        out[parent] = true;
    }

    int max = 0;
    for(int i=1;i<=N;i++)
    {
        int diameter;
        if(out[i] == true)
            continue;
        
        diameter = dfs(i,0);
        if(max < diameter)
            max = diameter;
    }

    cout << max << endl;
}

int dfs(int now, int pre)
{
    int ans = 0;

    for(int i=0;i<node[now].edge.size();i++)
    {
        if(node[now].edge[i].first == pre)
            continue;

        int dist = node[now].edge[i].second;
        dist += dfs(node[now].edge[i].first, now);
        if(ans < dist)
            ans = dist;
    }

    return ans;
}