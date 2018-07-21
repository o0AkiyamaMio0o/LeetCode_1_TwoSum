class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0,ans;
        string ansStr;
        bool state = 0;
        
        for(int i = 0;i<s.size();i++){
            ans = 0;
            state = 0;
            int i1 = i,i2 = i-1;
            
            do{
                if(ans>max){
                    max = ans;
                    state = 1;
                }
                i1--;
                i2++;
                ans+=2;
            }while(i1>=0&&i2<s.size()&&s[i1]==s[i2]);
            if(state)
                ansStr.assign(s.begin()+i1+1,s.begin()+i2);
            
            ans = 1;
            state = 0;
            i1 = i,i2 = i;
            
            do{
                if(ans>max){
                    max = ans;
                    state = 1;
                }
                i1--;
                i2++;
                ans+=2;
            }while(i1>=0&&i2<s.size()&&s[i1]==s[i2]);
            if(state)
                ansStr.assign(s.begin()+i1+1,s.begin()+i2);
        }
        return ansStr;
    }
};