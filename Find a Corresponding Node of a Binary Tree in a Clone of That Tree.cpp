/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if(cloned == null){
            return null;
        } 
        if(cloned.val == target.val){
            return cloned;
        }
        if(isLeaf(cloned)){
            return null;
        }
        TreeNode ret = getTargetCopy(original,cloned.left,target);
        if(ret != null){
            return ret;
        }
        ret = getTargetCopy(original,cloned.right,target);
        if(ret != null){
            return ret;           
        }
        return null;
    }
    private boolean isLeaf(final TreeNode node){
        return node.left == null && node.right == null;
    }
}