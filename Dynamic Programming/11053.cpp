#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int N;
    cin >> N;

    vector<int> in(N+1);
    vector<int> dp(N+1);

    for(int i=0;i<N;i++)
        cin >> in[i];
    
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++) {
            if(in[i] > in[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
            
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
	
	return 0;
}