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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr,*root = nullptr;
        
        while(l1!=nullptr||l2!=nullptr){
            if(l1==nullptr){
                if(ans!=nullptr){
                    ans->next = new ListNode(l2->val);
                    ans = ans->next;    
                }
                else
                    ans = new ListNode(l2->val);
                l2=l2->next;
            }
            else if(l2==nullptr){
                if(ans!=nullptr){
                    ans->next = new ListNode(l1->val);
                    ans = ans->next;
                }
                else
                    ans = new ListNode(l1->val);
                l1=l1->next;
            }
            else if(l1->val >= l2->val){
                if(ans!=nullptr){
                    ans->next = new ListNode(l2->val);
                    ans = ans->next;
                }
                else
                    ans = new ListNode(l2->val);
                l2=l2->next;
            }
            else{
                if(ans != nullptr){
                    ans -> next = new ListNode(l1->val);
                    ans = ans->next;
                }
                else
                    ans = new ListNode(l1->val);
                l1=l1->next;
            }
            
            if(root == nullptr)
                root = ans;
        }
        return root;
    }
};