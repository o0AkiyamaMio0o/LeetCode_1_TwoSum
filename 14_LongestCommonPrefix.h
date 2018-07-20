static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = 0;
        string ans;
        if(strs.empty())
            return ans;
        
        while(n<strs[0].size()){
            char c = strs[0][n];
            
            for(auto i : strs)
                if(n >= i.size()||i[n] != c)
                    return ans;
                
            ans.append(1,c);
            n++;
        }
        return ans;
    }
};