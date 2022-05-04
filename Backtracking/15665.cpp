#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void back(vector<int> input, int M, int N, vector<int> ans)
{
    if(M == 0)
    {
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    int prev = -1;
    for(int i=0;i<N;i++)
    {
        int flag = 0;

        if(input[i] == prev)
            continue;
        
        prev = input[i];
        vector<int> next = ans;
        next.push_back(input[i]);

        back(input, M-1, N, next);
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
    back(input, M, N, ans);
}