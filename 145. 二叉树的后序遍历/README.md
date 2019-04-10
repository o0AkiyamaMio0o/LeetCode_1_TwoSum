## 145. 二叉树的后序遍历



> 给定一个二叉树，返回它的 *后序* 遍历。
>
> **示例:**
>
> ```
> 输入: [1,null,2,3]  
>    1
>     \
>      2
>     /
>    3 
> 
> 输出: [3,2,1]
> ```
>
> **进阶:** 递归算法很简单，你可以通过迭代算法完成吗？



直接递归就完了，迭代算法没做。



```C++
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
```

