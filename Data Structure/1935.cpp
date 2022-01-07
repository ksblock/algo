#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int N, data, index;
    double first, second;
    double result;
    string postfix;
    vector<int> alphabet;
    stack<double> st;

    cin >> N;
    cin >> postfix;
    for(int i=0;i<N;i++)
    {
        cin >> data;
        alphabet.push_back(data);
    }

    for(int i=0;i<postfix.length();i++)
    {
        if(postfix[i] == '+')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            
            result = first + second;
            st.push(result);
        }
        else if(postfix[i] == '-')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            
            result = second - first;
            st.push(result);
        }
        else if(postfix[i] == '*')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            
            result = first * second;
            st.push(result);
        }
        else if(postfix[i] == '/')
        {
            first = st.top();
            st.pop();
            second = st.top();
            st.pop();
            
            result = (double) second / first;
            st.push(result);
        }
        else
        {
            index = postfix[i] - 'A';
            st.push(alphabet[index]);
        }
    }

    cout <<fixed;
    cout.precision(2);
    cout << st.top() << endl;
}