static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string tens="IXCM";
    string fives="VLD";
    
    int romanToInt(string s) {
        string::iterator iter = s.begin();
        int ans = 0;
        
        while(iter!=s.end()){
            if(tens.find(*iter)!=-1){
                if(iter+1!=s.end()&&*(iter+1)==fives[tens.find(*iter)]){
                    ans +=  pow(10,tens.find(*iter)) * 4;
                    iter++;
                }
                else if(iter+1!=s.end()&&*(iter+1)==tens[tens.find(*iter)+1]){
                    ans += pow(10,tens.find(*iter)) * 9;
                    iter++;
                }
                else
                    ans += pow(10,tens.find(*iter));
            }
            else if(fives.find(*iter)!=-1){
                ans += 5*pow(10,fives.find(*iter));
            }
            iter++;
        }
        
        return ans;        
    }
};