static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        
        int t = x,ans = 0;
        while(t){
            ans = ans*10 + t%10;
            t/=10;
        }
        return x == ans;
    }
};