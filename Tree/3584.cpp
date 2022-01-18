#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        map<int,int> m;
        vector<bool> v(N+1);

        for(int i=0;i<N+1;i++)
            v[i] = false;

        int parent, child;
        for(int i=0;i<N-1;i++)
        {
            cin >> parent >> child;
            m[child] = parent;
            v[child] = true; 
        }

        int root;
        for(int i=1;i<N;i++)
            if(v[i] == false)
                root = i;

        int A, B;
        cin >> A >> B;

        vector<int> As;
        vector<int> Bs;

        int now = A;
        while(now != root)
        {
            As.push_back(now);
            now = m[now];
        }
        As.push_back(root);

        now = B;
        while(now != root)
        {
            Bs.push_back(now);
            now = m[now];
        }
        Bs.push_back(root);

        int ans;
        for(int i=As.size()-1, j=Bs.size()-1; i>=0 && j>=0;i--,j--)
        {
            //cout << As[i] << " and " << Bs[j] << endl;
            if(As[i] != Bs[j])
                break;
            ans = As[i];
        }

        cout << ans << endl;
    }
}