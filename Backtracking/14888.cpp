#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans_max = -1111111111, ans_min = 1111111111;
int N, op[4];
vector<int> A;
vector<int> seq;

int cal()
{
    int re = A[0];
    for(int i=0;i<N-1;i++)
    {
        if(seq[i] == 0)
            re = re + A[i+1];
        else if(seq[i] == 1)
            re = re - A[i+1];
        else if(seq[i] == 2)
            re = re * A[i+1];
        else
            re = re/ A[i+1];
    }

    return re;
}

void back(int idx)
{
    if(idx==N - 1)
    {
        int ans = cal();

        ans_max = max(ans, ans_max);
        ans_min = min(ans, ans_min);

        return;
    }

    for(int i=0;i<4;i++)
    {
        if(op[i] == 0)
            continue;

        op[i]--;
        seq.push_back(i);
        back(idx+1);
        op[i]++;
        seq.pop_back();
    }
}

int main()
{
    cin >> N;

    int num;
    for(int i=0;i<N;i++)
    {
        cin >> num;
        A.push_back(num);
    }

    for(int i=0;i<4;i++)
        cin >> op[i];

    back(0);

    cout << ans_max << "\n" << ans_min << "\n";
}