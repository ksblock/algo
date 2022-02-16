#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> city(N);
    vector<long long> road(N-1);

    for(int i=0;i<N-1;i++)
        cin >> road[i];
    for(int i=0;i<N;i++)
        cin >> city[i];

    long long ans = city[0] * road[0];
    int now = 0;

    for(int i=1;i<N - 1;i++)
    {
        if(city[i] < city[now]) // 지금 도시가 더 쌈 -> 주유소 변경
            now = i;

        ans += city[now] * road[i];
    }

    cout << ans << endl;
}