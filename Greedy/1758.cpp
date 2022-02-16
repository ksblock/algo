#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int main()
{
    int N, tip;
    vector<int> tips;
    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        cin >> tip;
        tips.push_back(tip);
    }

    sort(tips.begin(), tips.end(), greater<>());

    long long ans = 0;
    for(int i=0;i<N;i++)
    {
        if(tips[i] - i > 0)
            ans += (tips[i] - i);
    }

    cout << ans << endl;
}