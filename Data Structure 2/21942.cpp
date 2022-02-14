#include<iostream>
#include<map>
#include<string>
using namespace std;

#define int int64_t

struct books{
    int v{};
    map<string, int> table;
};

map<string, books> Map; 

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int N, L, F;
    string string_L;

    cin >> N >> string_L >> F;

    int Day_L = stoi(string_L.substr(0,3));
    int Hour_L = stoi(string_L.substr(4,2));
    int Minute_L = stoi(string_L.substr(7,2));

    L = Day_L * 1440 + Hour_L * 60 + Minute_L;

    while(N--)
    {
        string date, time, P, M;
        cin >> date >> time >> P >> M;

        int Time;

        int Month = stoi(date.substr(5,2));
        int Day = stoi(date.substr(8,2));
        int Hour = stoi(time.substr(0,2));
        int Minute = stoi(time.substr(3,2));

        int Month_cum = 0;
        for(int i=0;i<Month;i++)
            Month_cum += month[i];

        Time = Month_cum * 1440 + Day * 1440 + Hour * 60 + Minute;

        auto& chk = Map[M];
        if(chk.table.count(P))
        {
            if((Time - chk.table[P] - L) > 0)
                chk.v += (Time - chk.table[P] - L) * F;
            chk.table.erase(P);
        }
        else
            chk.table[P] = Time;
    }

    bool chk = false;
    auto iter = Map.begin();
    while(iter != Map.end())
    {
        if(iter->second.v != 0)
        {
            chk = true;
            cout << iter->first << " " << iter->second.v << "\n";
        }
        iter++;
    }
    if(chk == false)
        cout << -1 << '\n';
}