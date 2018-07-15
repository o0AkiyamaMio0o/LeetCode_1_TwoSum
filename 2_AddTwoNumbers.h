class Solution {
public:
    int caculate(ListNode* l1,ListNode* l2){
        
        int add1 = 0,add2 = 0;
        if(l1!=nullptr)
            add1 = l1->val;
        if(l2!=nullptr)
            add2 = l2->val;
        
        return add1 + add2;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        bool tCarry=0;//to store if current caculation results in carrying
        ListNode* tNode=nullptr,*ansNode=nullptr;
        while(l1!=nullptr||l2!=nullptr){
            if(tNode!=nullptr)
            {
                tNode->next = new ListNode((caculate(l1, l2)+static_cast<int>(tCarry))%10);
                tNode = tNode->next;
            }
            else
                tNode = new ListNode((caculate(l1, l2)+static_cast<int>(tCarry))%10);
            if(ansNode==nullptr)
                ansNode = tNode;
            tCarry=(caculate(l1, l2)+static_cast<int>(tCarry)>=10);
            if(l1!=nullptr)
                l1 = l1->next;
            if(l2!=nullptr)
                l2 = l2->next;
        }
        
        if(tCarry)
            tNode->next = new ListNode((1));
        
        return ansNode;
    }
};