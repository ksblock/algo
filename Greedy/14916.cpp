#include<iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int five, two;

    five = N/5;
    N -= five * 5;

    if(N % 2 == 0)
        two = N/2;
    else
    {
        five--;
        N+=5;
        two = N/2;
    }

    if(five < 0)
        cout << -1 << endl;
    else    
        cout << five + two << endl;
}