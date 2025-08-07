class Solution {
public:
//          THREE TEMP NODES
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* t1 = head;
        ListNode* t2 = t1->next;
        ListNode* t3 = t2->next;

        t1->next = NULL;
        
        while(t2 != NULL){
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            if(t3) t3 = t3->next;
        }
        return t1;
    }
};
