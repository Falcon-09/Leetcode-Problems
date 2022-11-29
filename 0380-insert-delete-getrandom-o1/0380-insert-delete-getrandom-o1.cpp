class RandomizedSet {
public:
    unordered_set<int> m;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)){
            return false;
        }
        m.insert(val);
        arr.clear();
        for(int it : m){
            arr.push_back(it);
        }
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)){
            return false;
        }
        m.erase(val);
        arr.clear();
        for(int it : m){
            arr.push_back(it);
        }
        return true;
    }
    
    int getRandom() {
       
        int sz = arr.size();
        int idx = rand()%sz;
        return arr[idx];
    }
};
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */