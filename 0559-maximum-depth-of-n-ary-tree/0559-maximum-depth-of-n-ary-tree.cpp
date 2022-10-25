/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans(Node* root){
        if(!root){
            return 0;
        }
        int maxy=0;
        for(int i=0;i<root->children.size();i++){
            maxy=max(maxy,ans(root->children[i]));
        }
        return 1+maxy;
    }
    int maxDepth(Node* root) {
        return ans(root);
    }
};