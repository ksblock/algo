#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N+1);

    v[1] = 1;
    v[2] = 3;

    for(int i=3;i<=N;i++)
        v[i] = (v[i-1] + v[i-2]*2) % 10007;

    cout << v[N] << endl;
}