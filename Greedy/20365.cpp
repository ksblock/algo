#include<iostream>
#include<string>
using namespace std;

int main()
{
    int N;
    string in;

    cin >> N;
    cin >> in;

    int B_num = 0, R_num = 0;
    
    for(int i=0;i<N;i++)
    {
        if(in[i] == 'B')
        {
            while(i < N && in[i] == 'B')
            {
                i++;
            }
            i--;

            B_num++;
        }
        else
        {
            while(i < N && in[i] == 'R')
            {
                i++;
            }
            i--;

            R_num++;
        }
    }

    int ans;
    if(R_num > B_num)
        ans = B_num + 1;
    else
        ans = R_num + 1;

    cout << ans << endl;

}