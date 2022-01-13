#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

struct circle
{
    int x, idx;
    bool open;
};

bool compare(const circle& a, const circle& b)
{
    return a.x < b.x;
}

int main()
{
    int N;
    cin >> N;

    vector<circle> v;
    stack<int> st;

    for(int i=0;i<N;i++)
    {
        int x, r;
        cin >> x >> r;
        v.push_back({x-r,i,true});
        v.push_back({x+r,i,false});
    }

    sort(v.begin(), v.end(), compare);

    for(int i=1;i<v.size();i++)
    {
        if(v[i].x == v[i-1].x)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(int i=0;i<v.size();i++)
    {
        if(v[i].open)
            st.push(v[i].idx);
        else if(v[i].idx == st.top())
            st.pop();
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}