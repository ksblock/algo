#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    set<string> s;
    for(int i=0;i<N;i++)
    {
        string input;
        cin >> input;
        s.insert(input);
    }

    int ans = 0;
    for(int i=0;i<M;i++)
    {
        string query;
        cin >> query;

        if(s.end() != s.find(query))
            ans++;
    }

    cout << ans << endl;
}