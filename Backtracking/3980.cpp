#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans;
int check[11];
int player[11][11];

void back(int play, int sum)
{
    if(play == 11)
    {
        ans = max(ans, sum);
        return;
    }

    for(int i=0;i<11;i++)
    {
        if(player[play][i] != 0 && check[i] == 0)
        {
            check[i] = 1;
            back(play+1, sum + player[play][i]);
            check[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T--)
    {
        ans = 0;
        
        for(int i=0;i<11;i++)
            for(int j=0;j<11;j++)
                cin >> player[i][j];

        back(0, 0);

        cout << ans << "\n";
    }
}