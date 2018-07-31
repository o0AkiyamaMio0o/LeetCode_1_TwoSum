static const auto ____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<string> numToChar={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        queue<string> ansTemp;
        ansTemp.push("");
        
        while(ansTemp.front().size()!=digits.size()){
            for(auto i:numToChar[digits[ansTemp.front().size()]-'2'])
                ansTemp.push(ansTemp.front()+i);
            ansTemp.pop();
        }
        
        
        while(!ansTemp.empty()){
            ans.push_back(ansTemp.front());
            ansTemp.pop();
        }
        
        if(ans.size()==1)
            ans.clear();
            
        return ans;
    }
};