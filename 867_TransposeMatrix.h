static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A.size(),m = A[0].size();
        vector<vector<int>> ans;
        
        for(int i=0;i<m;i++){
            ans.push_back(vector<int>(0));
            for(int j = 0;j<n;j++){
                ans[i].push_back(A[j][i]);
            }
        }
        return ans;
    }
};