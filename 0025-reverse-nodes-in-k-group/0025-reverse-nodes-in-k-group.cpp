class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = head;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* head,int k){
            while(head && k--){
                head = head->next;
            }
            return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
            if(head == NULL) return NULL;
            ListNode* temp = head;
            ListNode* nxt = NULL;
            ListNode* prevNode = NULL;
            while(temp){
                ListNode* node = getKthNode(temp,k-1);
                if(node==NULL){
                    if(prevNode) prevNode->next = temp;
                    break;
                }
                nxt = node->next;
                node->next = NULL;
                reverseList(temp);
                if(head==temp){
                    head = node;
                }
                else{
                    prevNode->next = node;
                }
                    prevNode = temp;
                    temp = nxt;
                
            }
            return head;
    }
};