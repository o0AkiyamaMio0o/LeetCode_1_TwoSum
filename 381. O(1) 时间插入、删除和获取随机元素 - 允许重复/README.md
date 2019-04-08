### 381. O(1) 时间插入、删除和获取随机元素 - 允许重复

#### 题设

    设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。
    
    注意: 允许出现重复元素。
    
    - insert(val)：向集合中插入元素 val。
    - remove(val)：当 val 存在时，从集合中移除一个 val。
    - getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。

#### 题解

思路同 #380. 常数时间插入、删除和获取随机元素 把存储数据用的unordered_map改为unordered_multimap即可，需注意的是insert操作在找到时也仍需进行插入操作

#### 坑和注意

无

#### 代码

```C++
class RandomizedSet {
public:
    unordered_multimap<int,int> arr1;
    vector<unordered_multimap<int,int>::iterator> arr2;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(arr1.find(val)!=arr1.end())
            return false;
        
        unordered_multimap<int,int>::iterator temp=arr1.insert(pair<int,int>(val,arr2.size()));
        
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
```

