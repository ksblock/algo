#include<iostream>
#include<vector>
using namespace std;

void back(int st, int N, int M, vector<int> ans)
{
    if(M == 0)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=st;i<=N;i++)
    {
        vector<int> next_ans = ans;
        next_ans.push_back(i);
        back(i,N,M-1,next_ans);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> ans;
    back(1, N, M, ans);
}