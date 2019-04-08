## 92. 反转链表 II



> 反转从位置 *m* 到 *n* 的链表。请使用一趟扫描完成反转。
>
> **说明:**
> 1 ≤ *m* ≤ *n* ≤ 链表长度。
>
> **示例:**
>
> ```
> 输入: 1->2->3->4->5->NULL, m = 2, n = 4
> 输出: 1->4->3->2->5->NULL
> ```



一次遍历，遍历过程中无需存储各节点信息，该反转的地方改一下指针指向，注意反转部分和非反转部分的连接就没问题。

- 注意如果首节点就开始反转以及反转至末尾节点的处理



```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n)
            return head;
        
        ListNode* root=nullptr,*p=head,*t1,*t2,*lastReverse;
        
        //找到翻转的起始点
        while(m>1){
            root=p;
            p=p->next;
            
            m--;n--;
        }
        
        //存储起始点
        lastReverse=p;
        
        //while循环中为反转过程
        while(n>=1){
            t1=p->next;
            p->next=t2;
            t2=p;
            p=t1;
            
            n--;
        }
        
        //处理反转部分末尾结点的next
        lastReverse->next=p;
        
        //处理前段和反转部分的连接 注意首节点开始反转时的处理
        if(root!=nullptr){
            root->next=t2;
            return head;
        }else
            return t2;
    }
};
```

