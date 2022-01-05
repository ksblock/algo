#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, data;
    int head = 0;
    int tail = 0;
    string command;
    vector <int> v;

    cin >> N;

    while(N--)
    {
        cin >> command;

        if(command == "push")
        {
            cin >> data;
            v.push_back(data);
            tail++;
        } 
        else if(command == "pop")
        {
            if(head == tail)
                cout << -1 << "\n";
            else
            {
                cout << v[head] << "\n";
                head++;
            }
        }
        else if(command == "size")
        {
            cout << tail - head << "\n";
        }
        else if(command == "empty")
        {
            if(head == tail)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(command == "front")
        {
            if(head == tail)
                cout << -1 << "\n";
            else
                cout << v[head] << "\n";
        }
        else
        {
            if(head == tail)
                cout << -1 << "\n";
            else
                cout << v[tail-1] << "\n";
        }
    }
}