#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<int, string> name;
    map<string, int> number;

    for(int i=1;i<=N;i++)
    {
        string pokemon;
        cin >> pokemon;
        name[i] = pokemon;
        number[pokemon] = i;
    }

    for(int i=0;i<M;i++)
    {
        string query;
        cin >> query;

        if(query[0] >= '0' && query[0] <= '9')
            cout << name[stoi(query)] << '\n';
        else
            cout << number[query] << '\n';
    }
}