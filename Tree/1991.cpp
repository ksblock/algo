#include<iostream>
#include<vector>
#include <string>
using namespace std;

vector<int> v[30];

string pre(int now)
{
    if(now == 0)
        return "";
    
    string ans = "";
    ans += 'A' + now - 1;

    ans += pre(v[now][0]);
    ans += pre(v[now][1]);

    return ans;
}
string in(int now)
{
    if(now == 0)
        return "";
    
    string ans = "";

    ans += in(v[now][0]);
    ans += 'A' + now - 1; 
    ans += in(v[now][1]);

    return ans;
}
string post(int now)
{
    if(now == 0)
        return "";
    
    string ans = "";

    ans += post(v[now][0]);    
    ans += post(v[now][1]);
    ans += 'A' + now - 1;

    return ans;
}

int main()
{
    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        char p, l, r;
        cin >> p >> l >> r;

        int pa, le, ri;
        pa = p - 'A' + 1;

        if(l == '.')
            v[pa].push_back(0);
        else
            v[pa].push_back(l -'A' + 1);

        if(r == '.')
            v[pa].push_back(0);
        else
            v[pa].push_back(r - 'A' + 1);
    }

    cout << pre(1) << endl;
    cout << in(1) << endl;
    cout << post(1) << endl;
}