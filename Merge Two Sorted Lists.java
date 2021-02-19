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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null && l2 == null)
            return null;
        ListNode ret = new ListNode();
        ListNode cur = ret;
        ListNode last = null;
        ListNode l1Next = l1;
        ListNode l2Next = l2;
        while(l1Next != null && l2Next != null){
            if(l1Next.val < l2Next.val){
                cur.val = l1Next.val;
                l1Next = l1Next.next;
            }else{
                cur.val = l2Next.val;
                l2Next = l2Next.next;
            }
            if(l1Next == null || l2Next == null){
                last = cur;               
            }
            cur.next = new ListNode();
            cur = cur.next;
        }
        while(l1Next != null){
            cur.val = l1Next.val;
            l1Next = l1Next.next;
            if(l1Next == null){
                last = cur;
            }
            cur.next = new ListNode();
            cur = cur.next;
        }
        while(l2Next != null){
            
            cur.val = l2Next.val;
            l2Next = l2Next.next;
            if(l2Next == null){
                last = cur;
            }
            cur.next = new ListNode();
            cur = cur.next;
        }
        
        last.next = null;
        return ret;
    }
}