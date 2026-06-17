
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(-1);
            ListNode* temp = dummy;
            int carry = 0;
            while(l1 || l2 || carry){
                int val = 0;
                if(l1!=NULL){
                    val += l1->val;
                }
                if(l2!=NULL){
                    val += l2->val;
                }
                val += carry;
                ListNode* node = new ListNode(val%10);
                carry = val/10;
                temp->next = node;
                temp = temp->next;
                if(l1)l1 = l1->next;
                if(l2)l2 = l2->next;
            }
            return dummy->next;
    }
};