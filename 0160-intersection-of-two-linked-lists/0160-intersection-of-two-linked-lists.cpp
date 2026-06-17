class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* tempa = headA;
            ListNode* tempb = headB;
            if(tempa == NULL || tempb == NULL) return NULL;
            while(true){
                if(tempa==tempb) return tempa;
                else if(tempa == NULL) tempa = headB;
                else if(tempb == NULL) tempb = headA;
                else{
                    tempa = tempa->next;
                    tempb = tempb->next;
                }
            }
            return tempa;
    }
};