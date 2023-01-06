class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
      unordered_map<int, int> um;
      for(auto &i: nums) um[i]++;
      vector<int> ans;
      for(auto &[a, b]: um){
        // if(um.find(a + 1) == um.end() and um.find(a - 1) == um.end() and um[a] == 1)
        //   ans.emplace_back(a);
        if(um.find(a + 1) != um.end() or um.find(a - 1) != um.end() or um[a] != 1)
          continue;
        else ans.emplace_back(a);
      }
      return ans;
    }
};