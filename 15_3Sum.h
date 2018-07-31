static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
        
		if (nums.size()<3)
			return ans;
        
        sort(nums.begin(), nums.end());
        
        int t=INT_MIN;
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==t)
                continue;
            else
                t=nums[i];
            
            int sum = nums[i]+nums[i+1]+nums[nums.size()-1];
            
            int j=i+1,k=nums.size()-1,jTemp=nums[j],kTemp=nums[k];
            
            while(j!=k){
                if(sum>0){
                    sum-=kTemp;
                    
                    while(nums[k]==kTemp&&k>j)
                        k--;
                    kTemp=nums[k];
                    sum+=kTemp;
                }else if(sum<0){
                    sum-=jTemp;
                    
                    while(nums[j]==jTemp&&j<k)
                        j++;
                    jTemp=nums[j];
                    sum+=jTemp;
                }else if(sum==0){
                    ans.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    
                    sum-=jTemp;sum-=kTemp;
                    
                    while(nums[j]==jTemp&&j<k)
                        j++;
                    jTemp=nums[j];
                    sum+=jTemp;
                    
                    while(nums[k]==kTemp&&k>j)
                        k--;
                    kTemp=nums[k];
                    sum+=kTemp;
                }
                
            }
        }

		return ans;
	}
};