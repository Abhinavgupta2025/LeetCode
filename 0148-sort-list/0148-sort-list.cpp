class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
         ListNode* dummy = new ListNode(-1);
         ListNode* temp  = dummy;
         while(a && b){
            if(a->val<=b->val){
                temp->next = a;
                temp = temp->next;
                a = a->next;
            }
            else{
                temp->next = b;
                temp = temp->next;
                b = b->next;
            }
         }
         while(a){
            temp->next = a;
            temp = temp->next;
            a = a->next;
         }
          while(b){
            temp->next = b;
            temp = temp->next;
            b = b->next;
         }
         return dummy->next;
    }
    ListNode* checkMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
           if(!head || !head->next) return head;
            ListNode* temp = head;
            ListNode* mid  = checkMiddle(head);
            ListNode* temp2 = mid->next;
            mid->next = NULL;
            ListNode* a = sortList(temp);
            ListNode* b = sortList(temp2);
            ListNode* ans = merge(a,b);
            return ans;
    }
};