#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = n / 5; 
    while (ans >= 0) 
    { 
        int left = n - ans * 5; 
        if (left % 3 == 0) 
        { 
            ans = ans + left / 3; 
            break; 
        } 
        ans--;
    } 
    cout << ans;
}