#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> v(N);
    for(int i=0;i<N;i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    long long max = 0;
    if(N % 2 == 1)
    {
        max = v[N-1];
        N--;
    }

    for(int i=0;i<N/2;i++)
        if(v[i] + v[N - i - 1] > max)
            max = v[i] + v[N - i - 1];

    cout << max << endl;
}