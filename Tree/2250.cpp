#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

struct Node
{
    int left, right;
};

vector<Node> node;
queue<int> q[10001];
map<int,int> m;
int chk[10001];
int cnt = 1;

void in(int now, int level)
{
    if(node[now].left == -1 && node[now].right == -1)
    {
        q[level].push(cnt);
        cnt++;
        return;
    }

    if(node[now].left != -1)
    {
        in(node[now].left, level+1);
    }
    
    q[level].push(cnt);
    cnt++;

    if(node[now].right != -1)
    {
        in(node[now].right, level+1);
    }
}

int main()
{
    int N;
    cin >> N;
    node.resize(N+1);
    

    for(int i=0;i<N;i++)
    {
        int p, l, r;
        cin >> p >> l >> r;

        node[p].left = l;
        node[p].right = r;

        if(l != -1)
            chk[l] = 1;
        if(r != -1)
            chk[r] = 1;
    }

    int root;
    for(int i=1;i<=N;i++)
    {
        if(chk[i] == 0)
        {
            root = i;
            break;
        }
    }

    in(root, 1);

    int max_level = 0;
    int max_width = 0;
    for(int i=1;q[i].size()!=0;i++)
    {
        if(q[i].size()==1)
        {
            if(max_width < 1)
            {
                max_level = i;
                max_width = 1;
            }
        }
        else
        {
            int width = q[i].back() - q[i].front() + 1;
            if(max_width < width)
            {
                max_level = i;
                max_width = width;
            }
        }
    }

    cout << max_level << " " << max_width;
}