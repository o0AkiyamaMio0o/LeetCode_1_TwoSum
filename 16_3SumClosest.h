static const auto ____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if(nums.size()<3)
            return 0;
        
        sort(nums.begin(),nums.end());
        
        int sum;
        pair<int,int> ans=pair<int,int>(0,INT_MAX);
        
        for(int i=0;i<nums.size()-2;i++){
            sum=nums[i]+nums[i+1]+nums[nums.size()-1];
            if(nums[i]+nums[i+1]+nums[i+2]-target>=ans.second)
                return ans.first;
                
            int j=i+1,k=nums.size()-1;
            
            while(j!=k){
                if(sum==target)
                    return sum;
                
                if(abs(sum-target)<ans.second)
                    ans=pair<int,int>(sum,abs(sum-target));
                
                if(sum>target){
                    sum-=nums[k];
                    k--;
                    sum+=nums[k];
                }
                    
                else if(sum<target){
                    sum-=nums[j];
                    j++;
                    sum+=nums[j];
                }   
            }
        }
        
        return ans.first;
    }
};