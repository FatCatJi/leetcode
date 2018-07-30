class LFUCache {
private:
    struct KeyData {
        int value;
        int frequence;
        list<int>::iterator it;
    };
    
    const int lfuCapacity;
    int minFrequence;
    unordered_map<int, KeyData> keyMap; // <key, (value, frequence, iterator of list of frequenceMap)>
    unordered_map<int, list<int>> frequenceMap; // <frequence, key list>
    
    void increaseFrequence(int key) {
        int frequence = (keyMap[key].frequence)++;
        frequenceMap[frequence].erase(keyMap[key].it);
        keyMap[key].it = frequenceMap[frequence + 1].insert(frequenceMap[frequence + 1].begin(), key);
        if (frequenceMap[frequence].empty() && frequence == minFrequence) {
            frequenceMap.erase(frequence);
            minFrequence = frequence + 1;
        }
    }
    
public:
    LFUCache(int capacity) : lfuCapacity(capacity) {
    }
    
    int get(int key) {
        int value = -1;
        unordered_map<int, KeyData>::iterator iter = keyMap.find(key);
        if (iter != keyMap.end()) {
            value = iter->second.value;
            increaseFrequence(key);
        }
        return value;
    }
    
    void put(int key, int value) {
        if (lfuCapacity <= 0) {
            return;
        }
        unordered_map<int, KeyData>::iterator iter = keyMap.find(key);
        if (iter == keyMap.end()) {
            if (keyMap.size() >= lfuCapacity) {
                int eraseKey = frequenceMap[minFrequence].back();
                frequenceMap[minFrequence].pop_back();
                if (frequenceMap[minFrequence].empty()) {
                    frequenceMap.erase(minFrequence);
                }
                keyMap.erase(eraseKey);
            }
            KeyData keyData = {value, 1, frequenceMap[1].insert(frequenceMap[1].begin(), key)};
            keyMap[key] = keyData;
            minFrequence = 1;
        } else {
            keyMap[key].value = value;
            increaseFrequence(key);
        }
    }
};
