class Solution {
public:
    int helper(vector<int> &a, vector<int> &b, vector<int> &c){
      return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1]);
    }
  
    vector<vector<int>> outerTrees(vector<vector<int>>& t) {
      if(t.size() <= 3) return t;
      int n = t.size();
      sort(t.begin(), t.end());
      
      vector<vector<int>> up;
      up.emplace_back(t[0]);
      up.emplace_back(t[1]);
      for(int i = 2; i < n; i++){
        int s = up.size();
        while(s >= 2 and helper(up[s - 2], up[s - 1], t[i]) > 0){
          up.pop_back(); s--;
        }
        up.emplace_back(t[i]);
      }
      
      vector<vector<int>> down;
      down.emplace_back(t[n - 1]);
      down.emplace_back(t[n - 2]);
      for(int i = n - 3; i >= 0; i--){
        int s = down.size();
        while(s >= 2 and helper(down[s - 2], down[s - 1], t[i]) > 0){
          down.pop_back(); s--;
        }
        down.emplace_back(t[i]);
      }
      
      for(auto &i: down){
        up.emplace_back(i);
      }
      sort(up.begin(), up.end());
      up.erase(unique(up.begin(), up.end()), up.end());
      return up;
    }
};