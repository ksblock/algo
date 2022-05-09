#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> desc;
void back(long long now)
{
    

    int remain = now % 10;
    for(int i= 0 ;i<remain;i++)
    {
        desc.push_back(now*10 + i);
        back(now*10 + i);
    }
}

int main()
{
    int N;
    cin >> N; 

    for(long long i=0;i<10;i++)
    {
        desc.push_back(i);
        back(i);
    }

    sort(desc.begin(), desc.end());

    if(N > desc.size())
        cout << -1;
    else
        cout << desc[N-1];
}