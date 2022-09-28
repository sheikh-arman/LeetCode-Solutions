class Solution {
public:

    void solve(ListNode* head, int n, int&count){
        if(head->next) solve(head->next, n, count);
        
		//just disconnecting means... deleting
        if(count==n) head->next = head->next->next;  
        
        count++;
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy ->next = head;
        int count = 0;
        solve(dummy, n, count);
        return dummy->next;
    }
};