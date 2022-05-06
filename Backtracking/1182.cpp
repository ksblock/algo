#include<iostream>
#include<vector>
using namespace std;

int N, S;
vector<int> input;

long long back(int idx, long long sum, int cnt)
{
    //cout << idx << " " << sum << "\n";

    if(idx == N)
    {
        if(sum == S && cnt != 0)
            return 1;

        return 0;
    }
    
    long long re = 0;
    re += back(idx + 1, sum, cnt);
    re += back(idx + 1, sum + input[idx], cnt + 1);

    return re;
}

int main()
{
    cin >> N >> S;

    int n;
    for(int i=0;i<N;i++){
        cin >> n;
        input.push_back(n);
    }

    long long ans = back(0, 0, 0);
    cout << ans;
}