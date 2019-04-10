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
    void levelOrderBottom(vector<vector<int>>& arr,TreeNode* root,int depth=0){
        if(!root)
            return;
        
        if(arr.size()<=depth)
            arr.push_back(vector<int>());
        
        arr[depth].push_back(root->val);
        
        levelOrderBottom(arr,root->left,depth+1);
        levelOrderBottom(arr,root->right,depth+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        
        levelOrderBottom(ans,root);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};