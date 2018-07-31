static const auto ____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        
        numRows--;
        
        string ans;
        
        for(int i = 0;i < s.size();i+=(numRows)*2){
            ans+=s[i];
        }
        for(int row = 1;row<numRows;row++)
            for(int i = row;i< s.size();i+=row*2){
                ans+=s[i];
                
                i+=(numRows-row)*2;
                if(i>=s.size())
                    break;
                ans+=s[i];
            }

        for(int i = numRows;i < s.size();i+=(numRows)*2){
            ans+=s[i];
                }
        return ans;
    }
};