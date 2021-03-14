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
    ListNode* swapNodes(ListNode* head, int k) {
        int arr[100000];
        ListNode* cur = head;
        int idx = 0;
        while(cur != nullptr){
            arr[idx++] = cur->val;
            cur = cur->next;
        }
        int temp = arr[k-1];
        arr[k-1] = arr[idx-k];
        arr[idx-k] = temp;
        ListNode* newHead = new ListNode(arr[0]);
        ListNode* newCur = newHead;
        for(int i=1;i<idx;i++){
            ListNode* nextCur = new ListNode(arr[i]);
            newCur->next = nextCur;
            newCur = nextCur;
        }
        return newHead;
    }
};