#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

class MinStack
{
private:
    Node *topNode;

public:
    MinStack()
    {
        topNode = nullptr;
    }

    void push(int val)
    {
        if (!topNode)
        {
            topNode = new Node(val);
        }
        else
        {
            Node *newNode = new Node(val);
            newNode->next = topNode;
            topNode = newNode;
        }
    }

    void pop()
    {
        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top()
    {
        return topNode->val;
    }

    int getMin()
    {
        int minVal = topNode->val;
        Node *temp = topNode->next;
        cout << "MinVal: " << minVal << endl;

        while (temp)
        {
            cout << "temp->val: " << temp->val << endl;
            if (minVal < temp->val)
            {
                minVal = temp->val;
            }
            temp = temp->next;
        }

        return minVal;
    }
};

int main()
{
    MinStack *obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);

    cout << obj->getMin() << endl;

    delete obj;
}
