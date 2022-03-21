#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v(21);

    v[0] = 0;
    v[1] = 1;

    int n;

    cin >> n;

    for(int i=2;i<=n;i++)
    {
        v[i] = v[i-1] + v[i-2];
    }

    cout << v[n] << endl;
}