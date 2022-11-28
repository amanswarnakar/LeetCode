class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& v){
      int n = v.size();
      unordered_map<int, int> um;
      for(int i = 0; i < n; i++){
        um[v[i][1]]++;
        um[v[i][0]] = um[v[i][0]];
      }
      vector<vector<int>> ans(2, vector<int>(0));
      for(auto &p: um){
        if(p.second == 0) 
          ans[0].emplace_back(p.first);
        if(p.second == 1) 
          ans[1].emplace_back(p.first);
      }
      sort(ans[0].begin(), ans[0].end());
      sort(ans[1].begin(), ans[1].end());
      return ans;
    }
};