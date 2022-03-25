#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string board[101][101];

string add(string a, string b)
{
    int sum = 0;
    string re;
    
    while(!a.empty() || !b.empty() || sum != 0)
    {
        if(!a.empty())
        {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(!b.empty())
        {
            sum += b.back() - '0';
            b.pop_back();
        }
        
        re.push_back(sum%10 + '0');
        sum/=10;
    }
    
    reverse(re.begin(), re.end());
    return re;
}

string cal(int n, int m)
{
    if(board[n][m] != "")
        return board[n][m];
    if(n == m)
        return "1";
    if(m == 0)
        return "1";
    
    board[n][m] =  add(cal(n-1, m),cal(n-1, m-1));
    return board[n][m];
}

int main()
{
    int m,n;
    cin >> n >> m;
    
    cout << cal(n,m) << endl;
}