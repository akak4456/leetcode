/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int val;
    void solve(TreeNode* cur, int remainHeight){
        if(remainHeight == 0){
            TreeNode* newLeftNode = new TreeNode(val);
            TreeNode* newRightNode = new TreeNode(val);
            newLeftNode->left = cur->left;
            newRightNode->right = cur->right;
            cur->left = newLeftNode;
            cur->right = newRightNode;
            return;
        }
        if(cur->left != NULL){
            solve(cur->left,remainHeight-1);
        }
        if(cur->right != NULL){
            solve(cur->right,remainHeight-1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        val = v;
        if(d == 1){
            TreeNode* newRoot = new TreeNode(val,root,nullptr);
            return newRoot;
        }else{
            solve(root,d-2);
            return root;
        }
    }
};