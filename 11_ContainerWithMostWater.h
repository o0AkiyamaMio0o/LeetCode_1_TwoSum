static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>> ridgeL,ridgeR;
        int max=INT_MIN,highest = INT_MIN,peak,temp;
        
        for(int i=0;i<height.size();i++){
            if(height[i]>highest){
                highest=height[i];
                peak=i;
                ridgeL.push_back(pair<int,int>(i,height[i]));
            }
        }
        
        highest = INT_MIN;
        for(int i=height.size()-1;i>=peak;i--){
            if(height[i]>highest){
                highest=height[i];
                ridgeR.push_back(pair<int,int>(i,height[i]));
            }
        }
        
        
        for(auto i:ridgeL){
            for(auto j:ridgeR){
                
                if((temp=(j.first-i.first)*min(i.second,j.second))>max)
                   max=temp;
                
                if(i.second<=j.second)
                    break;
            }
                
        
        }
            
        
        return max;
    }
};