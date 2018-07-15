class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> hash;
        
        for(int i = 0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end())
                return vector<int>{hash.find(target-nums[i])->second,i};
            hash.insert(pair<int,int>(nums[i],i));
        }
    }
};