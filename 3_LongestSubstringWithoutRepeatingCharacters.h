static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0,max = 0;
        set<char> checkRepeat;
        
        bool state = 1;
        int i,j;
        
        for(i = 0,j = 0;i < s.size();i++){
            
            for(;state&&j < s.size();j++){
                if(checkRepeat.insert(s[j]).second == 0){
                    state = 0;
                    break;
                }
                
                ans++;
                if(ans>max)
                    max = ans;
            }
            
            if(state == 0){
                checkRepeat.erase(s[i]);
                ans--;
                if(checkRepeat.insert(s[j]).second){
                    ans++;
                    state = 1;
                    j++;
                }
            }
        }
        return max;
    }
};