#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main()
{
    int N, K;
    while(1)
    {
        cin >> N >> K;
        if(N==0&&K==0)
            break;

        map<int,int> m;
        queue<pair<int,int>> leaf;//node 번호, 입력 번호
        vector<int> v[N+1];

        int root, target, now_parent;

        for(int i=1;i<=N;i++)
        {
            int node;
            cin >> node;

            if(i==1)//root
            {
                leaf.push(make_pair(i,node));
                now_parent = i;
                root = i;
            }
            else
            {
                if(node-1 != leaf.back().second)
                {
                    now_parent = leaf.front().first;
                    leaf.pop();
                }

                v[now_parent].push_back(i);
                m[i] = now_parent;

                leaf.push(make_pair(i,node));
            }

            if(node == K)
                target = i;
        }

        if(target == root)
        {
            cout << 0 << endl;
            continue;
        }
        int parent = m[target];
        if(parent == root)
        {
            cout << 0 << endl;
            continue;
        }
        int grand = m[parent];

        vector<int> uncle;
        for(int i=0;i<v[grand].size();i++)
        {
            if(v[grand][i] != parent)
                uncle.push_back(v[grand][i]);
        }

        int count = 0;
        for(int i=0;i<uncle.size();i++)
        {
            count += v[uncle[i]].size();
        }

        cout << count << endl;
    }
}