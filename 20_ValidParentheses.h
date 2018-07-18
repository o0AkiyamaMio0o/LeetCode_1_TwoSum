class Solution {
public:
    string back = ")]}";
    
    bool scan(string &s,string::iterator &iter,int type){
        iter++;
        while(iter!=s.end()){
            if(*iter == back[type])
                return 1;
            switch(*iter){
                case '(':
                    if(scan(s,iter,0) == 0)
                        return 0;
                    break;
                case '[':
                    if(scan(s,iter,1) == 0)
                        return 0;
                    break;
                case '{':
                    if(scan(s,iter,2) == 0)
                        return 0;
                    break;
                default:return 0;
            }
            iter++;
        }
        return 0;
    }
    
    bool isValid(string s) {
        string::iterator iter = s.begin();
        
        for(;iter!=s.end();iter++){
            switch(*iter){
                case '(':
                    if(scan(s,iter,0) == 0)
                        return 0;
                    break;
                case '[':
                    if(scan(s,iter,1) == 0)
                        return 0;
                    break;
                case '{':
                    if(scan(s,iter,2) == 0)
                        return 0;
                    break;
                default:return 0;
            }
        }
        
        return 1;
    }
};