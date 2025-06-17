#include <bits/stdc++.h>
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
    // my incorrect code : 
    // ListNode *insertionSortList(ListNode *head)
    // {
    //     ListNode *newHead = new ListNode(0);
    //     ListNode *temp = head;

    //     while (temp)
    //     {
    //         ListNode *trav = newHead;
    //         ListNode *newNode = temp; // should have stored the temp->next.
    //         while (trav->next && trav->next->val < newNode->val)
    //         {
    //             trav = trav->next;
    //         }
    //         newNode->next = trav->next;
    //         trav->next = newNode;
    //         temp = temp->next;
    //     }
    //     return newHead->next;
    // }

    // to correctly understand what was the issue i did dry run on this test case : 4 2 1 3
    // correct version 
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *newHead = new ListNode(0);
        ListNode *temp = head;

        while (temp)
        {
            ListNode *trav = newHead;
            ListNode *newNode = temp->next ;
            while (trav->next && trav->next->val < temp->val)
            {
                trav = trav->next;
            }
            temp->next = trav->next;
            trav->next = temp;
            temp = newNode ;
        }
        return newHead->next;
    }
};

int main()
{
    // Construct linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // Sort using insertion sort
    Solution sol;
    ListNode *sorted = sol.insertionSortList(head);

    // Print sorted list
    while (sorted)
    {
        cout << sorted->val << " ";
        sorted = sorted->next;
    }

    return 0;
}