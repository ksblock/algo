#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main()
{
    int N, C;
    vector<int> v;
    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        cin >> C;
        v.push_back(C);
    }

    sort(v.begin(), v.end(), greater<>());

    long long ans = 0;
    for(int i=0;i<N;i++)
    {
        if(i%3==2)
            continue;
        ans += v[i];
    }

    cout << ans << endl;
}