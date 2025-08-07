class Solution {
public:
    void fillAll(ListNode* temp, ListNode* list){
        while(list){
            temp->next = list;
            list = list->next;
            temp = temp->next;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);  
        ListNode* temp = dummy;

        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        fillAll(temp,list2);
        fillAll(temp,list1);

        return dummy->next;
    }
};
