/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        if(head->next->next == NULL)
        {
            head->next = NULL;
            return head;
        }
        ListNode * fast = head, *slow = head, *prev = head;
        while(fast && fast->next)//find the middle element using fast and slow pointer
        {
            prev = slow;//keep another pointer prev which will give us one element before middle one
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};