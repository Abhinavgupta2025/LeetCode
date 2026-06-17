class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(!head->next && n==1) return NULL;
            ListNode* fast = head;
            ListNode* slow = head;
            for(int i=0;i<n;i++){
                fast = fast->next;
            }
            if(fast==NULL) return head->next;
            while(fast && fast->next){
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
            return head;
            
    }
};