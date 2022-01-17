#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, q;
    int a, b, t, k;

    cin >> N;
    vector<int> in(N+1);
    vector<int> out(N+1);
    for(int i=0;i<N-1;i++)
    {
        cin >> a >> b;
        in[a]++;
        in[b]++;
    }

    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> t >> k;
        if(t==1)
        {
            if(in[k]==1)
                cout << "no\n";
            else 
                cout << "yes\n";
        }
        else
        {
            cout << "yes\n";
        }
    }

}