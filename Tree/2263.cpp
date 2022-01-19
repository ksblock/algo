#include<iostream>
using namespace std;

int in[100001];
int post[100001];

void pre(int root, int l, int r)
{
    if(root < 0)
        return;
    //cout << root << " " << post[root] << endl;
    for(int i=l;i<r;i++)
    {
        if(in[i] == post[root])
        {
            cout << post[root] << " ";
            pre(root-r+i, l, i);
            pre(root-1,i+1,r);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> in[i];
    for(int i=0;i<N;i++)
        cin >> post[i];

    pre(N-1,0,N);
}

