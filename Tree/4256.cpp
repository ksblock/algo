#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int pre[1001], in[1001];

void post(int now, int l, int r)
{
    for(int i=l;i<r;i++)
    {
        if(in[i] == pre[now])
        {
            post(now+1, l, i);
            post(now+1+i-l,i+1,r);
            cout << in[i] << " ";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    
    while(T--)
    {
        int N;
        cin >> N;


        for(int i=0;i<N;i++)
        {
            cin >> pre[i];
        }
        for(int i=0;i<N;i++)
        {
            cin >> in[i];
        }

        post(0,0,N);
        cout << '\n';
    }
}