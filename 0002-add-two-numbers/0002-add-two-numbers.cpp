class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(-1);
            ListNode* temp  = dummy;
            int carry = 0;
            while(l1 && l2){
                int val = l1->val + l2->val + carry;
                ListNode* node = new ListNode(val%10);
                carry = val/10;
                temp->next = node;
                temp = temp->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            while(l1){
                int val = l1->val + carry;
                ListNode* node = new ListNode(val%10);
                carry = val/10;
                temp->next = node;
                temp = temp->next;
                l1 = l1->next;
            }
            while(l2){
                int val = l2->val + carry;
                ListNode* node = new ListNode(val%10);
                carry = val/10;
                temp->next = node;
                temp = temp->next;
                l2 = l2->next;
            }
            if(carry){
                ListNode* node = new ListNode(carry);
                temp->next = node;
            }
            return dummy->next;
    }
};