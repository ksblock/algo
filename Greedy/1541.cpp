#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
    string input;
    queue<int> q;   // + => -1, - => -2
    int flag = 1;
    cin >> input;

    for(int i=0;i<input.length();i++)
    {
        if(input[i] == '+')
            continue;
        else if(input[i] == '-')
            flag = 0;
        else
        {
            int num = 0;
            while(i < input.length() && input[i] != '+' && input[i] != '-')
            {
                num *= 10;
                num += input[i] - '0';
                i++;
            }

            if(flag == 0)
                num *= -1;

            q.push(num);
            i--;
        }
    }

    int now = 0, ans = 0;
    while(!q.empty())
    {
        ans += q.front();
        q.pop();
    }

    cout << ans << endl;
}