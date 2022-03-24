#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        vector<int> v(N+1);
        v[1] = 1;
        v[2] = 2;
        v[3] = 4;

        for(int i=4;i<=N;i++)
            v[i] = v[i-1] + v[i-2] + v[i-3];

        cout << v[N] << endl;
    }
}