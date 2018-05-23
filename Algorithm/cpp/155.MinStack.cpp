/*
* 155.Min Stack
* Design a stack that supports push,pop,top,and retrieving the mininmum element in constant time.
*      1.push(x) -- Push element x onto stack.
*      2.pop() -- Removes the element on top of the stack.
*      3.top() -- Get the top element.
*      4.getMin() -- Retrieve the minimum element in the stack.
* Example:
*      MinStack minstack = new MinStack();
*      minStack.push(-2);
*      minStack.push(0);
*      minStack.push(-3);
*      minStack.getMin(); --> Returns -3.
*      minStack.pop();
*      minStack.top();    --> Returns 0.
*      minStack.getMin(); --> Returns -2.
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }

    void push(int x) {
        st.push(x);

        int curMin = INT_MAX;
        if (!minSt.empty())
            curMin = minSt.top();

        if (x <= curMin)
            minSt.push(x);
    }

    void pop() {
        if (!st.empty())
        {
            int v = st.top();
            st.pop();

            if (minSt.top() == v)
                minSt.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }

    void clear()
    {
        while (!st.empty())
        {
            st.pop();
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
    cout << "--- expected output [0,0,0,2]" << endl;

    MinStack ms;
    ms.push(2);
    ms.push(0);
    ms.push(3);
    ms.push(0);

    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;
    ms.pop();
    cout << ms.getMin() << endl;

    //ms.clear();

    return 0;
}
