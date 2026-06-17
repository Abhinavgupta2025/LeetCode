class Solution {
public:
    ListNode* checkMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt  = head;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
         ListNode* temp = head;
         ListNode* mid = checkMiddle(head);
         ListNode* temp2 = mid->next;
         mid->next = NULL;
         temp2 = reverse(temp2);
         while(temp && temp2){
            if(temp->val != temp2->val){
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
         }
         return true;
    }
};