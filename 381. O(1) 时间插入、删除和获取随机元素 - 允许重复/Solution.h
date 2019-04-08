class RandomizedCollection {
public:
    unordered_multimap<int,int> arr1;
    vector<unordered_map<int,int>::iterator> arr2;
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
                srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool tempFlag=arr1.find(val)==arr1.end();
        
        unordered_multimap<int,int>::iterator temp=arr1.insert(pair<int,int>(val,arr2.size()));
        
        arr2.push_back(temp);
        
        return tempFlag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
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
    
    /** Get a random element from the collection. */
    int getRandom() {
        return arr2[rand()%arr2.size()]->first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */