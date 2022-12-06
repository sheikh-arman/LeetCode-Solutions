class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!(head->next)) return head;
        ListNode *p=head,*p1=head->next,*p2;
        while(p1&&p1->next){
            p2=p1->next;
            p1->next=p2->next;
            p2->next=p->next;
            p->next=p2;
            p=p->next;
            p1=p1->next;
        }
        return head;
    }
};