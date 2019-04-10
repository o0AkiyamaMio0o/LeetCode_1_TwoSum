/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void postorderTraversal(vector<int>& arr,TreeNode* root){
        if(!root)
            return;
        
        postorderTraversal(arr,root->left);
        postorderTraversal(arr,root->right);
        
        arr.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        postorderTraversal(ans,root);
        
        return ans;
    }
};