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
    long long totalTreeSum=0,result=0;
    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
    {
        if(!root)
            return 0;
        long long sum=SumUnder(root->left)+SumUnder(root->right)+root->val; //Get the sum of current subtree.
        result=max(result,sum*(totalTreeSum-sum));    //Get the max product after making current subtree as a separate tree
        return sum;
    }
    public:
    int maxProduct(TreeNode* root) 
    {
        int MOD=(int)1e9+7;
        totalTreeSum=SumUnder(root);
        SumUnder(root);
        return result%MOD;
    }
};