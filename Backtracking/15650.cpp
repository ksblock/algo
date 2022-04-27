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
    }

    for(int i = st; i <= N; i++)
    {
        vector<int> next_ans = ans;
        //vector<int> next_chk = chk;

        next_ans.push_back(i);

        back(i+1, N, M - 1, next_ans);
    }
}

int main()
{
    int M, N;
    cin >> N >> M;

    vector<int> ans;
    vector<int> chk(N+1);

    back(1, N, M, ans);
}