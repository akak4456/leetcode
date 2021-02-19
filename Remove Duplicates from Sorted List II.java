/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
            return null;
        ListNode cur = head;
        ListNode prev = head;
        while(!isLast(cur)){
            //System.out.println(cur.val);
            if(isSameWithNext(cur)){
                ListNode first = cur;
                while(!isLast(first)&&isSameWithNext(first)){
                    first = first.next;
                }
                if(cur == head){
                    head = first.next;
                }else{
                    prev.next = first.next;
                }
                cur = first.next;
                if(cur == null)
                    break;
            }else{
                prev = cur;
                cur = cur.next;
            }
        }
        return head;
    }
    private boolean isLast(ListNode cur){
        return cur.next == null;
    }
    private boolean isSameWithNext(ListNode cur){
        return cur.val == cur.next.val;
    }
}