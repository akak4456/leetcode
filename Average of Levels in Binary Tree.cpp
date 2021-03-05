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
    vector<long long int> sum;
    vector<int> cnt;
    void solve(TreeNode* root, int level){
        if(sum.size() < level+1){
            sum.resize(level+1);
            cnt.resize(level+1);
        }
        sum[level] += root->val;
        cnt[level]++;
        if(root->left != nullptr){
            solve(root->left,level+1);
        }
        if(root->right != nullptr){
            solve(root->right,level+1);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root,0);
        vector<double> ans;
        for(int i=0;i<sum.size();i++){
            ans.push_back((double)sum[i]/(double)cnt[i]);
        }
        return ans;
    }
};