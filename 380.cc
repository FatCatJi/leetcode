/*Design a data structure that supports all following operations in average O(1) time.
insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/
class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> vals;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) == map.end()) {
            vals.push_back(val);
            map[val] = vals.size() - 1;
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int, int>::iterator iter = map.find(val);
        if (iter == map.end()) {
            return false;
        } else {
            map[vals.back()] = iter->second;
            swap(vals[iter->second], vals.back());
            vals.pop_back();
            map.erase(val);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
