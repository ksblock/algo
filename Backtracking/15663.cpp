#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void back(vector<int> input, int N, int M, vector<pair<int, int>> ans)
{
    if(M == 0)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i].first << " ";
        cout << "\n";
        return;
    }

    int prev = -1;
    for(int i = 0;i<N;i++)
    {
        int flag = 0;
        if(prev == input[i])
            continue;

        for(int j=0;j<ans.size();j++)
        {
            if(i == ans[j].second)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 0)
        {
            vector<pair<int,int>> next = ans;
            next.push_back(make_pair(input[i], i));
            prev = input[i];

            back(input, N, M-1, next);
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

    vector<pair<int, int>> ans;
    back(input, N, M, ans);
}