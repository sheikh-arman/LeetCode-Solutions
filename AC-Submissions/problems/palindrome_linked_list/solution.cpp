// Copied. I'll solve later.

class Solution {
    
    ListNode* reverse(ListNode* head){
        ListNode *dummy = NULL, *next = NULL;
        
        while(head){
            next = head-> next;
            head -> next = dummy;
            dummy = head;
            head = next;
        }
        
        return dummy;
    }
    
    bool solveDailyChallenge(ListNode* head){
        ListNode *slow = head, *fast = head;
        
        if(fast->next == NULL) return true;
        
        while(fast->next != NULL and fast -> next -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        slow ->next = reverse(slow->next); 
        
        slow = slow->next;
        ListNode* cmp = head;
        
        while(slow!=NULL){
            if(slow->val != cmp->val) return false;
            slow = slow->next;
            cmp = cmp->next;
        }
        
        return true;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        return solveDailyChallenge(head);
    }
};