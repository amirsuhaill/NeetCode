class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* temp3 = head->next->next;
        temp1->next = NULL;
        while(temp2){
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            if(temp3) temp3 = temp3->next;
        }
        return temp1;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = NULL;

        head2 = reverse(head2);

        ListNode* temp1 = head;
        ListNode* temp2 = head2;

        while(temp1 && temp2){
            ListNode* t1Next = temp1->next;
            ListNode* t2Next = temp2->next;

            temp1->next = temp2;
            temp2->next = t1Next;

            temp1 = t1Next;
            temp2 = t2Next;
        }
    }
};
