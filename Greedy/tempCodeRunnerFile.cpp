#include<iostream>
#include<algorithm>
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

    sort(v.begin(), v.end());

    long long ans = 0;
    for(int i=0;i<N;i++)
    {
        if(i%3==0 && N - i >= 3)
            continue;
        ans += v[i];
    }

    cout << ans << endl;
}