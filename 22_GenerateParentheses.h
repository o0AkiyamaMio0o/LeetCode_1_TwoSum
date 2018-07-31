static const auto ____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class A{
public:
    int done,toDo;
    string now;
    A(int a,int b,string c):done(a),toDo(b),now(c){}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<A> ansTemp;
        
        A aTemp(0,n,"");
        ansTemp.push(aTemp);
        
        while(aTemp.done!=0||aTemp.toDo!=0){
            if(aTemp.toDo!=0)
                ansTemp.push(A(aTemp.done+1,aTemp.toDo-1,aTemp.now+"("));
            if(aTemp.done!=0)
                ansTemp.push(A(aTemp.done-1,aTemp.toDo,aTemp.now+")"));
            
            ansTemp.pop();
            aTemp=ansTemp.front();
        }
        
        while(!ansTemp.empty()){
            ans.push_back(ansTemp.front().now);
            ansTemp.pop();
        }
        
        return ans;
    }
};