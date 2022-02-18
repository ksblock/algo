#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int N;
    int ans = 0;
    int before = -1;
    cin >> N;

    vector<pair<int,int>> v(N);

    for(int i=0;i<N;i++)
        cin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end(), compare);

    for(int i=0;i<N;i++)
    {
        if(v[i].first >= before)
        {
            before = v[i].second;
            ans++;
        }
    }

    cout << ans << endl;
}