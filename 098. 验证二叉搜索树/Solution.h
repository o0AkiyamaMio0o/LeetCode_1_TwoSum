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
    bool isValidBST(TreeNode* root,pair<bool,int> lowBound=pair<bool,int>(false,INT_MIN),pair<bool,int> upBound=pair<bool,int>(false,INT_MAX)) {
        if(!root)
            return true;
        
        if((lowBound.first&&root->val<=lowBound.second)||(upBound.first&&root->val>=upBound.second))
            return false;
        
        return isValidBST(root->left,lowBound,pair<bool,int>(true,min(upBound.second,root->val)))&&isValidBST(root->right,pair<bool,int>(true,max(lowBound.second,root->val)),upBound);
    }
};