#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void back(int idx, string str, int len)
{
    if(idx == len - 1)
    {
        cout << str << "\n";
        return;
    }

    for(int i=idx;i<len;i++)
    {
        if(i != idx && str[i] == str[idx])
            continue;
        if(str[i] != str[idx])
            swap(str[i], str[idx]);

        back(idx+1, str, len);
    }

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string in;
        cin >> in;

        sort(in.begin(), in.end());

        back(0, in, in.size());
    }
}