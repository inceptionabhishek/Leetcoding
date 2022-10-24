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
    int ans(TreeNode* root,int parent,int grandparent){
        if(!root){
            return 0;
        }
        //cout << grandparent << ' ' << parent  << ' ' << root->val << endl;
        int curr=0;
        if(grandparent%2==0){
            curr=root->val + ans(root->left,root->val,parent)+ans(root->right,root->val,parent);
        }else{
            curr=ans(root->left,root->val,parent)+ans(root->right,root->val,parent);
        }
        return curr;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int parent=-1;
        int grandparent=-1;
        return ans(root,parent,grandparent);
    }
};