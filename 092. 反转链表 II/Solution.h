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