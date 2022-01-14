#include<iostream>
#include<vector>
using namespace std;

int pow(int x)
{
    int re = 1;
    for(int i=0;i<x;i++)
        re*=2;
    return re;
}

int main()
{

    int N;
    cin >> N;

    vector<int> v[N];
    vector<int> ans[N];

    for(int i=0;i<pow(N)-1;i++)
    {
        int a;
        cin >> a;
        v[N-1].push_back(a);
    }

    for(int i=N;i>0;i--)
    {
        for(int j = 0;j<pow(i) - 1;j++)
        {
            if(j%2==0)
            {
                ans[i-1].push_back(v[i-1][j]);
            }
            else
            {
                v[i-2].push_back(v[i-1][j]);
            }
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }




}