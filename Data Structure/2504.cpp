#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    int ans;
    bool check = true;
    string input;
    cin >> input;

    stack<int> st;
    st.push(0);

    for(int i=0;i<input.length();i++)
    {
        if(input[i] == '(')
        {
            st.push(-1);
        }
        else if(input[i] == ')')
        {
            if(st.empty() || st.top() == -2) //) [)
            {
                check = false;
                break;
            }
            if(st.top() == -1)// ()
            {
                st.pop();
                if(st.top() != -1 && st.top() != -2)// 숫자()
                {
                    int top = st.top();
                    st.pop();
                    st.push(2 + top);
                }
                else    // (() [()
                    st.push(2);
            }
            else// 숫자)
            {
                int temp = st.top();
                st.pop();

                if(st.empty() || st.top() == -2)//[숫자) 숫자)
                {
                    check = false;
                    break;
                }
                else//(숫자)
                {
                    temp*=2;
                    st.pop();
                    
                    if(st.top() == -1 || st.top() == -2) //((숫자) [(숫자)
                        st.push(temp);
                    else//숫자(숫자)
                    {
                        int top = st.top();
                        st.pop();
                        st.push(temp + top);
                    }
                }
            }
        }
        else if(input[i] == '[')
        {
            st.push(-2);
        }
        else if(input[i] == ']')
        {
            if(st.empty() || st.top() == -1) //] (]
            {
                check = false;
                break;
            }
            if(st.top() == -2)// []
            {
                st.pop();
                if(st.top() != -1 && st.top() != -2)// 숫자[]
                {
                    int top = st.top();
                    st.pop();
                    st.push(3 + top);
                }
                else    // ([] [[]
                    st.push(3);
            }
            else// 숫자]
            {
                int temp = st.top();
                st.pop();

                if(st.empty() || st.top() == -1)//(숫자] 숫자]
                {
                    check = false;
                    break;
                }
                else//[숫자]
                {
                    temp*=3;
                    st.pop();
                    if(st.top() == -1 || st.top() == -2) //([숫자] [[숫자]
                        st.push(temp);
                    else//숫자[숫자]
                    {
                        int top = st.top();
                        st.pop();
                        st.push(temp + top);
                    }
                }
            }
        }
    }

    ans = st.top();
    st.pop();
    if(check == false || !st.empty())
        cout << 0 << endl;
    else
        cout << ans << endl;
}