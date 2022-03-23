#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M;
        cin >> N >> M;

        int arr[31][31] = { 0 };
        for(int i=1;i<=30;i++)
        {
            arr[i][i] = 1;
            arr[i][1] = i;
        }

        for(int i=1;i<=M;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(arr[i][j] != 0)
                    continue;
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }

        cout << arr[M][N] << endl;
    }
}