/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        int szA = 1,szB = 1;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA->next != NULL){
            szA++;
            curA = curA->next;
        }
        while(curB->next != NULL){
            szB++;
            curB = curB->next;
        }
        if(curA != curB)
            return NULL;
        curA = headA;
        curB = headB;
        if(szA > szB){
            for(int i=0;i<szA-szB;i++){
                curA = curA->next;
            }
        }else{
            for(int i=0;i<szB-szA;i++){
                curB = curB->next;
            }
        }
        while(curA != curB){
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};