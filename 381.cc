/*Design a data structure that supports all following operations in average O(1) time.
Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
*/
class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> map; // val, index in vals
    vector<int> vals;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = (map.find(val) == map.end());
        vals.push_back(val);
        map[val].insert(vals.size() - 1);
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        unordered_map<int, unordered_set<int>>::iterator iter = map.find(val);
        if (iter == map.end()) {
            return false;
        } else {
            int eraseIndex = *(iter->second.begin());
            iter->second.erase(eraseIndex);
            if (iter->second.empty()) {
                map.erase(val);
            }
            if (eraseIndex != (vals.size() - 1)) {
                map[vals.back()].erase(vals.size() - 1);
                map[vals.back()].insert(eraseIndex);
                swap(vals[eraseIndex], vals.back());
            }
            vals.pop_back();
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
