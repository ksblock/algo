#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N, K, ans = 0;
    cin >> N >> K;

    vector<int> v(N);
    for(int i=0;i<N;i++)
        cin >> v[i];

    for(int i=N-1;i>=0;i--)
    {
        int coin = K / v[i];
        ans += coin;

        K -= coin * v[i];
    }

    cout << ans << endl;
}