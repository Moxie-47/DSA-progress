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
    void reorderList(ListNode *head)
    {
        if (head->next == nullptr || head->next->next == nullptr)
            return;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode *first = head;
        ListNode *second = prev;
        while (second)
        {
            ListNode *first_ahead = first->next;
            ListNode *second_ahead = second->next;
            first->next = second;
            second->next = first_ahead;
            first = first_ahead;
            second = second_ahead;
        }
        return;
    }
};

void Print_List(ListNode* head){
    while(head){
        cout<<head->val<<" " ;
        head = head->next ;
    }
    cout<<endl;
}
int main()
{
    ListNode* head = new ListNode(1) ;
    head->next = new ListNode(2) ;
    head->next->next = new ListNode(3); 
    head->next->next->next = new ListNode(4); 
    Solution s ;
    s.reorderList(head) ;
    cout<<"Ater Reording : "<<endl;
    Print_List(head);
    return 0;
}