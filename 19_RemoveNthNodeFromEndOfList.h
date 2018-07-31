static const auto ____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<ListNode*> theList;
        ListNode* p=head;
        
        while(p!=nullptr){
            theList.push_back(p);
            p=p->next;
        }
        
        if(theList.size()<=1)
            return nullptr;
        
        if(n==theList.size()){
            return theList[1];
        }else{
            (*(theList.end()-n-1))->next=(*(theList.end()-n))->next;
        
        }
            
        return head;
    }
};