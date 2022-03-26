#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int flag = 0;
    vector<int> S(N+1);
    for(int i=0;i<N;i++)
        cin >> S[i];

    int l = 0, r = 0;
    int odd = 0;
    int ans = 0;

    if(S[0] % 2 == 0)
        odd = 0;
    else
        odd = 1;

    while(l <= r && r < N)
    {
        if(odd <= K && r + 1 < N)
        {
            r++;
            if(S[r] % 2 == 1)
                odd++;
        }
        else
        {
            if(S[l] % 2 == 1)
                odd--;
            l++;
        }

        if(odd <= K)
            ans = max(ans, (r + 1 - l - odd));
    }
    
    cout << ans << endl;
}