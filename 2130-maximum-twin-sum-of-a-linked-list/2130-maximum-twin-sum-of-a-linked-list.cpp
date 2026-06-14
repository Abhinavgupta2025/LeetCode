class Solution {
public:
        ListNode* reverse(ListNode* head){
            ListNode* curr = head;
            ListNode* next = head;
            ListNode* prev = NULL;
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    int pairSum(ListNode* head) {
       
            ListNode* fast = head;
            ListNode* slow = head;
            while(fast!=NULL && fast->next!=NULL){
                fast = fast->next->next;
                slow = slow->next;

            }
            slow = reverse(slow);
            int maxi = 0;
            ListNode* temp = slow;
            while(temp and head){
                maxi = max(maxi,temp->val+head->val);
                head = head->next;
                temp = temp->next;
            }
            return maxi;
    }
};