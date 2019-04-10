class Solution {
public:
    vector<int> temp=vector<int>(1,1);
    
    int numTrees(int n) {
        if(n<1)
            return 1;
        
        if(temp.size()>=n)
            return temp[n-1];
        
        int ans=0;
        
        for(int i=1;i<=n;i++)
            ans+=numTrees(i-1)*numTrees(n-i);
        
        temp.push_back(ans);
        
        return ans;
    }
};