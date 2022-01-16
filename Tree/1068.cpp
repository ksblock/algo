#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[51];

bool delete_node(int now, int del)
{
    for(int i=0;i<tree[now].size();i++)
    {
        if(tree[now][i] == del)
        {
            tree[now].erase(tree[now].begin() + i);
            return true;
        }
        bool chk = delete_node(tree[now][i], del);
        if(chk == true)
            return true;
    }
    return false;
}

int count_leaf(int now)
{
    if(tree[now].size() == 0)
        return 1;

    int ans = 0;
    for(int i=0;i<tree[now].size();i++)
    {
        ans += count_leaf(tree[now][i]);
    }

    return ans;
}

int main()
{
    int N;
    int root, data;
    int del;

    cin >> N;

    for(int i=0;i<N;i++)
    {
        cin >> data;
        if(data == -1)
            root = i;
        else
            tree[data].push_back(i);
    }

    cin >> del;

    if(del == root)
    {
        cout << 0 << endl;
        return 0;
    }

    bool check = delete_node(root, del);

    cout << count_leaf(root) << endl;
}