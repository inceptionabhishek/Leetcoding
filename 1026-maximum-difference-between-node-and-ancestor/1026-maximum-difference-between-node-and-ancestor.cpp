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
private:
    int ans=0;
    void helper(TreeNode* root,int currMin,int currMax){
        if(!root){
            return;
        }
        int ans1=max(abs(root->val-currMin),abs(root->val-currMax));
        ans = max(ans,ans1);
        currMin=min(root->val,currMin);
        currMax=max(root->val,currMax);
        helper(root->left,currMin,currMax);
        helper(root->right,currMin,currMax);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
};