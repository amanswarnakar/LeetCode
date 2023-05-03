class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& v1, vector<int>& v2) {
      set<int> st1, st2;
      for(auto &i: v1) st1.insert(i);
      for(auto &i: v2) st2.insert(i);
      vector<vector<int>> ans(2);
      for(auto i = st1.begin(); i != st1.end(); i++){
        if(st2.find(*i) == st2.end()) ans[0].emplace_back(*i);
      }
      for(auto i = st2.begin(); i != st2.end(); i++){
        if(st1.find(*i) == st1.end()) ans[1].emplace_back(*i);
      }
      return ans;
    }
};