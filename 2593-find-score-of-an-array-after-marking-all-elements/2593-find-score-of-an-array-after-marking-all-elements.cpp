class Solution {
public:
    long long findScore(vector<int>& v) {
      int n = v.size();
      map<int, vector<int>> mp;
      for(int i = 0; i < n; i++){
        mp[v[i]].emplace_back(i);
      }
      long long ans = 0;
      vector<bool> vis(n, false);
      for(auto &[f, s]: mp){
        for(auto &i: s){
          if(!vis[i]){
            ans += f;
            vis[i] = true;
            vis[max(i - 1, 0)] = true;
            vis[min(i + 1, n - 1)] = true;
          }
        }
      }
      return ans;
    }
};