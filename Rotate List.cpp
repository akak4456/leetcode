/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        if(head->next == nullptr)
            return head;
        ListNode* last = head;
        ListNode* lastPrev;
        int sz = 1;
        ListNode* tmp = head;
        while(tmp->next != nullptr){
            sz++;
            tmp = tmp->next;
        }
        k %= sz;
        for(int i=0;i<k;i++){
            while(last->next != nullptr){
                if(last->next->next == nullptr){
                    lastPrev = last;
                }
                last = last->next;
            }
            lastPrev->next = nullptr;
            last->next = head;
            head = last;
            last = head;
        }
        return head;
    }
};