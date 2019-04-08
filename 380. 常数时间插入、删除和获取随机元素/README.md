### 380. 常数时间插入、删除和获取随机元素

#### 题设

    设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。
    
    - insert(val)：当元素 val 不存在时，向集合中插入该项。
    - remove(val)：元素 val 存在时，从集合中移除该项。
    - getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。

#### 题解

采用哈希表达到同时满足插入删除的常数时间操作，同时用另一数组满足能随机获取元素（由于元素顺序性无要求，因此删除元素时先与数组末尾元素交换然后pop_back即可达到删除时的时间效率）

#### 坑和注意
- srand(time(NULL))需在初始化时进行一次，如果在每次rand()时调用一下，得到的随机数值将会是相同的

#### 代码

```C++
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
```

