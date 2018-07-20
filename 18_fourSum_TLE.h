class Solution {
public:
    map<int,vector<vector<int>>> seekCombinations(map<int,int> &Map,int i){
        map<int,vector<vector<int>>> ans;
        if(Map[i]>=4)
            return ans;
        
        ans[Map[i]*i].push_back(vector<int>(Map[i],i));
        
        if(Map[i] == 1){
            map<int,int>::iterator iter = Map.begin();
            
            for(;iter != Map.end();iter++){
                if(iter->first == i)
                    continue;
                for(map<int,int>::iterator iter1=iter;iter1!=Map.end();iter1++){
                    if(iter1->first == i)
                        continue;
                    if(iter1->first == iter->first&&iter1->second<2)
                        continue;
                    
                    ans[i+iter->first+iter1->first].push_back({i,iter1->first,iter->first});
                }
            }
        }
        
        if(Map[i] < 3 ){
            for(auto j : Map){
                if(j.first == i)
                    continue;
                
                vector<int> temp(1,j.first);
                vector<int> temp1(Map[i],i);
                temp.insert(temp.end(),temp1.begin(),temp1.end());
                ans[j.first+Map[i]*i].push_back(temp);
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        vector<int> tempArr;
        int actualTargetNum = 0;
        map<int,int> lMap,rMap;
        map<int,vector<vector<int>>> lPossible;
        
        for(auto i: nums){
            i*=4;
            if(i<target){
                lMap[target-i]++;
                
                //寻找由lMap[target-i]个i参与组成的
                for(auto &j:seekCombinations(lMap,target-i)){
                    for(auto &k:j.second){
                        for(auto &l:k)
                            l = target - l;
                        lPossible[j.first].push_back(k);
                    }
                }
            }
            
            else if(i>target){
                tempArr.push_back(i);
            }
            else
                actualTargetNum++;
        }
        if(actualTargetNum>=4)
            ans.push_back(vector<int>(4,target));
        

        for(auto i:tempArr){
            rMap[i-target]++;
            
            for(auto j:seekCombinations(rMap,i-target)){
                for(auto &k:j.second)
                    for(auto &l:k)
                        l+=target;
                for(auto k:lPossible[j.first]){
                    for(auto l:j.second){
                        if(l.size()+k.size()+actualTargetNum>=4&&l.size()+k.size()<=4){
                            vector<int> arr(4-l.size()-k.size(),target);
                            arr.insert(arr.end(),k.begin(),k.end());
                            arr.insert(arr.end(),l.begin(),l.end());
                            sort(arr.begin(),arr.end());
                            ans.push_back(arr);
                        }
                    }
                }
            }
        }
        
        for(auto &i:ans)
            for(auto &j:i)
                j/=4;
        
        return ans;
    }
};