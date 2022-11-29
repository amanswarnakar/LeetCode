class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
      
    }
    
    bool insert(int val) {
      return st.insert(val).second;
    }
    
    bool remove(int val) {
      if(st.count(val)){
        st.erase(val);
        return true;
      } else return false;
    }
    
    int getRandom() {
      int sz = st.size();
      vector<int> v(st.begin(), st.end());
      return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */