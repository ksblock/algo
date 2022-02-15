#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v;

    for(int i=0;i<N;i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), greater<>());

    int Max = 0;
    for(int i=0;i<v.size();i++)
    {
        int now = (i + 1) * v[i];
        if(Max < now)
            Max = now;
    }
    
    cout << Max << endl;
}