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
        ListNode* temp = head;
        while(temp && k){
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* temp = head;
            ListNode* prevNode = NULL;
            while(temp){
                ListNode* node = getKthNode(temp,k-1);
                if(node==NULL){
                    if(prevNode) prevNode->next = temp;
                    break;
                }
                ListNode* nxt = node->next;
                node->next = NULL;
                reverseList(temp);
                if(temp == head){
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