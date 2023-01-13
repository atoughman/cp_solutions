// problem link
// https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;

    void move_stack_elements(stack<int> &a, stack<int> &b)
    {
        // a -> 3,2,1(top)
        // b -> something

        while (!a.empty())
        {
            b.push(a.top());
            a.pop();
        }

        // after above operation
        // a -> empty
        // b -> something,1,2,3(top)
    }

    MyQueue()
    {
    }

    void push(int x)
    {
        move_stack_elements(st1, st2);

        st1.push(x);

        move_stack_elements(st2, st1);
    }

    int pop()
    {
        int x = st1.top();
        st1.pop();
        return x;
    }

    int peek()
    {
        return st1.top();
    }

    bool empty()
    {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */