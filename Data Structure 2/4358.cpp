#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt=0;
    map<string, int> m;
    string input;

    while(getline(cin, input))
    {
        m[input]++;
        cnt++;
    }

    cout << fixed;
    cout.precision(4);

    for(auto i:m)
    {
        cout << i.first << " " << (double) i.second * 100 / cnt << endl;
    }
}