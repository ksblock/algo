#include<iostream>
#include<string>
using namespace std;

int main()
{
    string A = "AAAA";
    string B = "BB";
    string input, output = "";

    cin >> input;

    int s = 0;
    int flag = 0;
    for(int i=0;i<input.length();i++)
    {
        if(input[i] == 'X')
            continue;

        int len = i - s;
        if(len % 2 == 1)
        {
            flag = 1;
            break;
        }

        int four, two;

        four = len/4;
        len -= four * 4;

        two = len/2;

        for(int i=0;i<four;i++)
            output += A;
        for(int i=0;i<two;i++)
            output += B;
        output += ".";

        s = i + 1;
    }

    int len = input.length() - s;
    if(len % 2 == 1)
    {
        flag = 1;
    }
    else
    {
        int four, two;

        four = len/4;
        len -= four * 4;

        two = len/2;

        for(int i=0;i<four;i++)
            output += A;
        for(int i=0;i<two;i++)
            output += B;
    }
    
    if(flag == 1)
        cout << -1 << endl;
    else
        cout << output << endl;
}