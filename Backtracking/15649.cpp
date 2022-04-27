#include<iostream>
#include<vector>
using namespace std;

void back(int N, int M, vector<int> ans, vector<int> chk)
{
    if(M == 0)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1;i<=N;i++)
    {
        if(chk[i] == 1)
            continue;

        vector<int> next_ans = ans;
        vector<int> next_chk = chk;

        next_ans.push_back(i);
        next_chk[i] = 1;

        back(N, M-1, next_ans, next_chk);
    }
}

int main()
{
    int M, N;
    cin >> N >> M;

    vector<int> ans;
    vector<int> chk(N+1);

    back(N, M, ans, chk);
}