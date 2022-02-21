#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main()
{
    int A, B;
    int ans = 1, flag = 0;
    cin >> A >> B;

    while(1)
    {
        if(B % 10 == 1)
            B/=10;
        else if(B % 2 == 0)
            B/=2;
        else if(B % 2 == 1)
        {
            ans = -1;
            break;
        }
        
        ans++;

        if(A==B)
            break;
        if(A > B)
        {
            ans = -1;
            break;
        }
    }

    cout << ans << endl;
}