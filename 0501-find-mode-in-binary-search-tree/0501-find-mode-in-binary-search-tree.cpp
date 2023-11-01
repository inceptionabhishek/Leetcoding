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
    unordered_map<int,int>ms;
    void trav(TreeNode* root){
        if(!root)return;
        ms[root->val]++;
        trav(root->left);
        trav(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        trav(root);
        int maxy=0,ele;
        vector<int>ans;
        for(auto j:ms){
            if(j.second>maxy){
                ele=j.first;
                maxy=j.second;
            }
        }
        for(auto j:ms){
            if(j.second==maxy){
                ans.push_back(j.first);
            }
        }
        return ans;
    }
};