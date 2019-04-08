class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX,ans=0;
        
        for(auto i:prices){
            if(i<min)
                min=i;
            
            else if(i-min>ans)
                ans=i-min;
        }
        
        return ans;
    }
};