#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N+1);
    vector<int> chk(N+1);

    for(int i=1;i<=N;i++)
        cin >> A[i];
    chk[1] = 1;

    for(int i=1;i<=N;i++)
    {
        if(chk[i] == 0)
            continue;
        
        for(int j=i+1;j<=N;j++)
        {
            int cal = (j-i) * (1+abs(A[i] - A[j]));
            if(cal <= K)
                chk[j] = 1;
        }
    }

    if(chk[N] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
}