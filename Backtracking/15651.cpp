#include<iostream>
#include<vector>
using namespace std;

void back(int N, int M, vector<int> ans)
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
        vector<int> next_ans = ans;
        next_ans.push_back(i);

        back(N, M-1, next_ans);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> ans;
    back(N, M, ans);
}