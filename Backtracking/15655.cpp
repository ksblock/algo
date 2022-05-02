#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void back(int st, vector<int> input, int N, int M, vector<int> ans)
{
    if(M == 0)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    for(int i=st;i<input.size();i++)
    {
        vector<int> next_ans = ans;
        next_ans.push_back(input[i]);

        back(i + 1, input, N, M-1, next_ans);
    }
}

int main()
{
    int M, N;
    cin >> N >> M;

    vector<int> input(N);
    for(int i=0;i<N;i++)
        cin >> input[i];

    sort(input.begin(), input.end());

    vector<int> ans;
    back(0, input, N, M, ans);
}