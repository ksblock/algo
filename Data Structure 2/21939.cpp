#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct problem
{
    int idx, level;
};

struct compare_max
{
    bool operator()(const problem& p1, const problem& p2)
    {
        if(p1.level == p2.level)
            return p1.idx < p2.idx;
        return p1.level < p2.level;
    }
};
struct compare_min
{
    bool operator()(const problem& p1, const problem& p2)
    {
        if(p1.level == p2.level)
            return p1.idx > p2.idx;
        return p1.level > p2.level;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<int, int> diff;
    priority_queue<problem, vector<problem>, compare_max> max_heap;
    priority_queue<problem, vector<problem>, compare_min> min_heap;

    for(int i=0;i<N;i++)
    {
        problem input;
        cin >> input.idx >> input.level;

        max_heap.push(input);
        min_heap.push(input);
        diff[input.idx] = input.level;
    }

    

    int M;
    cin >> M;
    
    for(int i=0;i<M;i++)
    {
        string op;
        cin >> op;

        if(op == "add")
        {
            problem input;
            cin >> input.idx >> input.level;

            max_heap.push(input);
            min_heap.push(input);
            diff[input.idx] = input.level;
        }
        else if(op == "recommend")
        {
            int x;
            cin >> x;

            if(x == 1)
            {
                while(!max_heap.empty() && diff[max_heap.top().idx] != max_heap.top().level)
                    max_heap.pop();

                cout << max_heap.top().idx << "\n";

            }
            else
            {
                while(!min_heap.empty() && diff[min_heap.top().idx] != min_heap.top().level)
                    min_heap.pop();

                cout << min_heap.top().idx << "\n";
                min_heap.pop();
            }
        }
        else if(op == "solved")
        {
            int x;
            cin >> x;

            diff[x] = 0;
        }
    }
}