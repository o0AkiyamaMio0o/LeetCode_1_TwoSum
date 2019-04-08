class RandomizedSet {
public:
    unordered_map<int,int> arr1;
    vector<unordered_map<int,int>::iterator> arr2;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(arr1.find(val)!=arr1.end())
            return false;
        
        unordered_map<int,int>::iterator temp=arr1.insert(pair<int,int>(val,arr2.size())).first;
        
        arr2.push_back(temp);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int,int>::iterator temp=arr1.find(val);
        
        if(temp==arr1.end())
            return false;
        
        arr2[temp->second]=*(arr2.end()-1);
        arr2[temp->second]->second=temp->second;
        arr2.pop_back();
        
        arr1.erase(temp);
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        // srand(time(NULL));
        
        return arr2[rand()%arr2.size()]->first;
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */