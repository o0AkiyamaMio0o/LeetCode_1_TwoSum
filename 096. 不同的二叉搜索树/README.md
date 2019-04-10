## 96. 不同的二叉搜索树



> 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
>
> **示例**
>
> ```
> 输入: 3
> 输出: 5
> 解释:
> 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
> 
>    1         3     3      2      1
>     \       /     /      / \      \
>      3     2     1      1   3      2
>     /     /       \                 \
>    2     1         2                 3
> ```



和095基本就是一道题，想通了$F(n)$要怎么来两道题都会做了。

在095中我们的思路是

> 求F(l,r)的结果集合只需遍历一遍，对索引为i的元素得到结果集F(l,i-1)<-i->F(i+1,r)，所有元素的结果集的合集即为结果。

对于本题中 F(l,r) 为集合元素数量，也就是说 $\begin{equation*}
F(l,r) = \sum_{i=l}^rF(l,i-1)×F(i+1,r)
\end{equation*}$

同时用DP加速，因为之前算过的 $F(l,r)$ 可能之后的计算过程中也会用到。




```C++
class Solution {
public:
    vector<int> temp=vector<int>(1,1);
    
    int numTrees(int n) {
        if(n<1)
            return 1;
        
        if(temp.size()>=n)
            return temp[n-1];
        
        int ans=0;
        
        for(int i=1;i<=n;i++)
            ans+=numTrees(i-1)*numTrees(n-i);
        
        temp.push_back(ans);
        
        return ans;
    }
};
```

