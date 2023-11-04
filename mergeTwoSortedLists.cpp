#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;

        ListNode *head, *walker;
        bool isFirstAssignment = true;

        while (list1 != nullptr && list2 != nullptr)
        {
            ListNode *newNode;
            if (list1->val <= list2->val)
            {
                newNode = new ListNode(list1->val);
                list1 = list1->next;
            }
            else if (list1->val > list2->val)
            {
                newNode = new ListNode(list2->val);
                list2 = list2->next;
            }

            if (isFirstAssignment)
            {
                walker = newNode;
                head = walker;
                isFirstAssignment = false;
            }
            else
            {
                walker = newNode;
            }

            walker = walker->next;
        }

        while (list1 != nullptr)
        {
            cout << "here" << endl;
            walker = new ListNode(list1->val);
            cout << walker->val << endl;
            walker = walker->next;
            list1 = list1->next;
        }

        while (list2 != nullptr)
        {
            cout << "here1" << endl;
            walker = new ListNode(list2->val);
            walker = walker->next;
            list2 = list2->next;
        }

        if (head->next != nullptr)
        {
            cout << "Node 2: " << head->next->val << endl;
        }
        else
        {
            cout << "head->next is nullptr" << endl;
        }

        return head;
    }
};

void PrintList(ListNode *list)
{
    while (list != nullptr)
    {
        cout << list->val;
        list != nullptr ? cout << " " : cout << endl;
        list = list->next;
    }
}

int main()
{
    Solution *solution = new Solution();
    ListNode *list1 = new ListNode(2);
    // list1->next = new ListNode(2);
    // list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    // list2->next = new ListNode(3);
    // list2->next->next = new ListNode(4);

    PrintList(solution->mergeTwoLists(list1, list2));

    delete solution;
    // delete list1->next->next;
    // delete list1->next;
    delete list1;
    // delete list2->next->next;
    // delete list2->next;
    delete list2;

    return 0;
}