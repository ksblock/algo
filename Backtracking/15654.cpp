#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void back(vector<int> input, int N, int M, vector<int> ans)
{
    if(M == 0)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    for(int i=0;i<input.size();i++)
    {
        int flag = 0;
        for(int j=0;j<ans.size();j++)
        {
            if(input[i] == ans[j])
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            vector<int> next_ans = ans;
            next_ans.push_back(input[i]);
            back(input, N, M-1, next_ans);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> input(N);
    for(int i=0;i<N;i++)
        cin >> input[i];

    sort(input.begin(), input.end());

    vector<int> ans;
    back(input, N, M, ans);
}