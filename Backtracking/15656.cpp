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
        return;
    }

    for(int i = 0;i<input.size();i++)
    {
        vector<int> next = ans;
        next.push_back(input[i]);

        back(input, N, M-1, next);
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