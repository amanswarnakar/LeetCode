class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
      st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
      vector<vector<int>> res;
      int l = *st.begin(), r = *st.begin();
      for(auto i = ++st.begin(); i != st.end(); i++){
        if(*i - r == 1) r = *i;
        else {
          res.push_back({l, r});
          l = *i; r = *i;
        }
      }
      res.push_back({l, r});
      return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */