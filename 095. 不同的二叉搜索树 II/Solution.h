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
    map<pair<int,int>,vector<TreeNode*>> temp;
    
    const vector<TreeNode*> generateTrees(int l,int r){
        if(l>r)
            return vector<TreeNode*>(1,nullptr);
        
        map<pair<int,int>,vector<TreeNode*>>::iterator t=temp.find(pair<int,int>(l,r));
        
        if(t!=temp.end())
            return t->second;
            
        vector<TreeNode*> ans;
        
        for(int i=l;i<=r;i++){
            vector<TreeNode*> t1=generateTrees(l,i-1);
            vector<TreeNode*> t2=generateTrees(i+1,r);
            
            for(auto j:t1)
                for(auto k:t2){
                    TreeNode* p=new TreeNode(i);
                    p->left=j;
                    p->right=k;
                    
                    ans.push_back(p);
                }
        }
        
        temp[pair<int,int>(l,r)]=ans;
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>();
        
        return generateTrees(1,n);
    }
};