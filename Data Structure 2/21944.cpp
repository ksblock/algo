#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

set<pair<int,int>> Q1[101];
set<pair<int,int>> Q2;
set<pair<int,int>> Q3; // 난이도, 번호

int level[100001];
int algo[100001];


void insert(int P, int L, int G)
{
    Q1[G].insert(make_pair(L, P));
    Q2.insert(make_pair(L, P));
    Q3.insert(make_pair(L, P));
}
int re1(int G, int x)
{
    if(x == 1)
        return prev(Q1[G].end())->second;
    else
        return Q1[G].begin()->second;
}
int re2(int x)
{
    if(x==1)
        return prev(Q2.end())->second;
    else
        return Q2.begin()->second;
}
int re3(int x, int L)
{
    if(x==1)
    {
        auto iter = Q3.upper_bound(make_pair(L-1, 999999));
        if(iter == Q3.end())
            return -1;
        else
            return iter->second;
    }
    else
    {
        auto iter = Q3.upper_bound(make_pair(L, -1));
        if(iter == Q3.begin())
            return -1;
        else
            return prev(iter)->second;
    }
}
void del(int P)
{
    int L = level[P];
    int G = algo[P];

    Q1[G].erase(make_pair(L, P));
    Q2.erase(make_pair(L, P));
    Q3.erase(make_pair(L, P));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    while(N--)
    {
        int P, L, G;
        cin >> P >> L >> G;

        insert(P, L, G);
        level[P] = L;
        algo[P] = G;
    }

    int M;
    cin >> M;

    while(M--)
    {
        string query;
        cin >> query;

        if(query == "recommend")
        {
            int G, x;
            cin >> G >> x;
            cout << re1(G, x) << endl;
        }   
        else if(query == "recommend2")
        {
            int x;
            cin >> x;
            cout << re2(x) << endl;
        }   
        else if(query == "recommend3")
        {
            int x, L;
            cin >> x >> L;
            cout << re3(x, L) << endl;
        } 
        else if(query == "add")
        {
            int P, L, G;
            cin >> P >> L >> G;
            
            insert(P, L, G);
            level[P] = L;
            algo[P] = G;
        }
        else if(query == "solved")
        {
            int P;
            cin >> P;

            del(P);
        }
    }
}