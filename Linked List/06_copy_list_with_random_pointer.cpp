class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone nodes and insert them next to original nodes
        Node* temp = head;
        while(temp){
            Node* curr = new Node(temp->val);
            curr->next = temp->next;
            temp->next = curr;
            temp = curr->next;
        }

        // Step 2: Assign random pointers to the copied nodes
        temp = head;
        while(temp){
            if(temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Step 3: Separate the two lists
        Node* ans = head->next;
        temp = head;
        while(temp){
            Node* copy = temp->next;
            temp->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;
            temp = temp->next;
        }
        
        return ans;
    }
};