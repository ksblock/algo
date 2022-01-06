#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main()
{
    int N, data;
    string command;
    deque<int> dq;
    cin >> N;

    while(N--)
    {
        cin >> command;
        if(command == "push_front")
        {
            cin >> data;
            dq.push_front(data);
        }
        else if(command == "push_back")
        {
            cin >> data;
            dq.push_back(data);
        }
        else if(command == "pop_front")
        {
            if(dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        else if(command == "pop_back")
        {
            if(dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
        else if(command == "size")
        {
            cout << dq.size() << endl;
        }
        else if(command == "empty")
        {
            if(dq.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if(command == "front")
        {
            if(dq.empty())
                cout << -1 << endl;
            else
                cout << dq.front() << endl;
        }
        else if(command == "back")
        {
            if(dq.empty())
                cout << -1 << endl;
            else
                cout << dq.back() << endl;
        }
    }

}