#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N = 1;
    while(N)
    {
        int cnt_root = 0;
        int in[10000],out[10000];
        for(int i=0;i<10000;i++)
        {
            in[i] = 0;
            out[i] = 0;
        }

        int u, v;
        cin >> u >> v;

        if(u == -1 && v == -1)
            break;
        if(u == 0 && v == 0)
        {
            cout << "Case " << N << " is a tree.\n";
            N++;
            continue;
        }

        in[v]++;
        out[u]++;

        while(u!=0 || v!=0)
        {
            cin >> u >> v;
            in[v]++;
            out[u]++;
        }

        bool flag = true;
        for(int i=0;i<10000;i++)
        {
            if(in[i]==0 && out[i] != 0)
                cnt_root++;
            if(in[i] > 1)
                flag = false;
        }

        if(cnt_root!=1)
            flag = false;

        if(flag == true)
            cout << "Case " << N << " is a tree.\n";
        else
            cout << "Case " << N << " is not a tree.\n";

        N++;        
    }
}