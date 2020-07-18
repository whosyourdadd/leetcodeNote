class RandomizedSet {
private:
    unordered_map<int, bool> Set;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (Set.find(val) != Set.end()) return false;
        Set[val] = true;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (Set.find(val) == Set.end()) return false;
        Set.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int rand = random() % Set.size();
        return next(Set.begin(), rand)->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
/**
KK
**/
