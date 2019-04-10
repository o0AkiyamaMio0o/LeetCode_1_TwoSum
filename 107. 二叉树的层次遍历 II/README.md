## 107. 二叉树的层次遍历 II



> 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
>
> 例如：
> 给定二叉树 `[3,9,20,null,null,15,7]`,
>
> ```
>     3
>    / \
>   9  20
>     /  \
>    15   7
> ```
>
> 返回其自底向上的层次遍历为：
>
> ```
> [
>   [15,7],
>   [9,20],
>   [3]
> ]
> ```



这个题就真的很简单了，直接递归，按照当前递归的层数放结果进数组对应的地方就行了。

- 注意放的时候因为不知道总层数是多少，如果先遍历一次得到总层数再放数字就太麻烦了，因此第一次放的时候先倒着放，层次越低(指递归调用的层数而非结点的深度)的放在前边，即arr[depth]中。遍历完了reverse一下就行，由于vector的swap操作是类似交换引用因此耗时很低。



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
```

