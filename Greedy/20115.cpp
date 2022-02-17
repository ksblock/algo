#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int x;
    int max = 0;
    double sum = 0;

    for(int i=0;i<N;i++)
    {
        cin >> x;
        if(x <= max)
        {
            sum += x;
        }
        else
        {
            sum += max;
            max = x;
        }
    }

    cout << sum / 2 + max << endl;
}