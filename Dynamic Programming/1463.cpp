#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N+1);

    v[1] = 0;

    for(int i = 2;i <= N;i++)
    {
        v[i] = v[i-1] + 1;
        if(i%3 == 0)
            v[i] = min(v[i], v[i/3] + 1);
        if(i%2 == 0)
            v[i] = min(v[i], v[i/2] + 1);
    }

    cout << v[N] << endl;
}