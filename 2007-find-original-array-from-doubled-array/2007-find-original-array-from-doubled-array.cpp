class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
      if(changed.size() % 2) return {};
      unordered_map<int, int> um;
      vector<int> ans;
      sort(changed.begin(), changed.end());
      for(int i : changed) um[i]++;
      for(auto i : changed){
        if(um[i] == 0) continue;
        if(um[i * 2] == 0) return {};
        ans.push_back(i);
        um[i]--; um[2 * i]--;
      }
      return ans;
    }
};