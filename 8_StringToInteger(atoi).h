static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int myAtoi(string str) {
        string::iterator iter = str.begin();
        int ans=0;
        bool flagNega = 0;
        
        if(*iter == '\"')
            iter++;
        
        while(*iter == ' ')
            iter++;
        
        if(*iter=='+')
            iter++;
        else if(*iter=='-'){
            flagNega = 1;
            iter++;
        }

        while(*iter>='0'&&*iter<='9'){
            ans *= 10;
            if(ans%10)
                return flagNega?INT_MIN:INT_MAX;
            ans += *iter-'0';
            if(ans<0)
                return flagNega?INT_MIN:INT_MAX;
            iter++;
        }
        return flagNega?-ans:ans;
    }
};