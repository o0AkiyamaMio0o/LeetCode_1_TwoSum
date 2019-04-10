## 98. 验证二叉搜索树



> 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
>
> 假设一个二叉搜索树具有如下特征：
>
> - 节点的左子树只包含**小于**当前节点的数。
> - 节点的右子树只包含**大于**当前节点的数。
> - 所有左子树和右子树自身必须也是二叉搜索树。
>
> **示例 1**
>
> ```
> 输入:
>     2
>    / \
>   1   3
> 输出: true
> ```
>
> **示例 2**
>
> ```
> 输入:
>     5
>    / \
>   1   4
>      / \
>     3   6
> 输出: false
> 解释: 输入为: [5,1,4,null,null,3,6]。
>      根节点的值为 5 ，但是其右子节点值为 4 。
> ```



题本身比较简单，递归搜索就行了没什么问题。注意好搜索的时候当前节点的上下限到底是什么，要用什么方式进行传递。主要是坑比较多。

- 左为小于，右为大于而非大于等于，因此不能用简单的 isLeft && val \< rootVal 来处理（实际上 isLeft ? val \< rootVal : val \> rootVal 也非常简单）
- 最开始上下限初值直接给的 INT_MAX , INT_MIN ，结果测试里有这么个节点**[2147483647]**，所以把上下限改为 pair < bool , int > 用 bool 键值来手动记录当前有无上/下限。
- 提示一下测试里还有**[2147483647,2147483647]**这么个节点，所以不能简单地用碰到极端值就不考虑来处理



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
    bool isValidBST(TreeNode* root,pair<bool,int> lowBound=pair<bool,int>(false,INT_MIN),pair<bool,int> upBound=pair<bool,int>(false,INT_MAX)) {
        if(!root)
            return true;
        
        if((lowBound.first&&root->val<=lowBound.second)||(upBound.first&&root->val>=upBound.second))
            return false;
        
        return isValidBST(root->left,lowBound,pair<bool,int>(true,min(upBound.second,root->val)))&&isValidBST(root->right,pair<bool,int>(true,max(lowBound.second,root->val)),upBound);
    }
};
```

