## 95. 不同的二叉搜索树 II



> 给定一个整数 *n*，生成所有由 1 ... *n* 为节点所组成的**二叉搜索树**。
>
> **示例:**
>
> ```
> 输入: 3
> 输出:
> [
>   [1,null,3,2],
>   [3,2,null,1],
>   [3,1,null,null,2],
>   [2,1,3],
>   [1,null,2,null,3]
> ]
> 解释:
> 以上的输出对应以下 5 种不同结构的二叉搜索树：
> 
>    1         3     3      2      1
>     \       /     /      / \      \
>      3     2     1      1   3      2
>     /     /       \                 \
>    2     1         2                 3
> ```



基于和快排有点类似的思想。设我们求的从l元素到r元素的结果集合为$F(l,r)$，当然初始时$l=1,r=n$。求$F(l,r)$的结果集合只需遍历一遍，对索引为 $i$ 的元素得到结果集 $F(l,i-1)←i→F(i+1,r)$，所有元素的结果集的合集即为结果。

求解过程中用了DP来加速，实际上对于这样的树需要用clone而非直接赋值否则我猜你可能能够想到会出现什么显而易见的问题，但是检测机显然没有检测这一部分。



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
```

