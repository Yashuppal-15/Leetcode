#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack
{
public:
    vector< pair<int, int> > st;

    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            // It means we are inserting first element
            pair<int, int> p;
            p.first = val;
            p.second = val;     // same value rakhi kyuki abhi tak ek hi value hai
            st.push_back(p);
        }
        else
        {
            pair<int, int> p;
            p.first = val;
            int puranaMin = st.back().second;
            p.second = min(puranaMin, val);
            st.push_back(p);
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        else
        {
            st.pop_back();
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;   // stack empty case
        }
        else
        {
            pair<int, int> rightMostPair = st.back();
            return rightMostPair.first;
        }
    }

    int getMin()
    {
        if (st.empty())
        {
            return -1;   // stack empty case
        }
        else
        {
            pair<int, int> rightMostPair = st.back();
            return rightMostPair.second;
        }
    }
};
