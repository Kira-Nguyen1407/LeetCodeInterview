#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    // void push(int value){
    //     dataStack.push(value);
    // }
    MinStack()
    {
    }

    void push(int val)
    {
        dataStack.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        if(!minStack.empty()){
            if (dataStack.top() == minStack.top())
            {
                minStack.pop();
            }
        }
        
        dataStack.pop();
    }

    int top()
    {
        return dataStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

int main()
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    // cout << obj->top() << endl;
    obj->push(0);
    obj->push(-3);
    int param_1 = obj->getMin();
    obj->pop();
    int param_2 = obj->top();
    int param_3 = obj->getMin();

    cout << "param_1: " << param_1 << ", param_2: " << param_2 << ", param_3: " << param_3 << endl;
    return 0;
}