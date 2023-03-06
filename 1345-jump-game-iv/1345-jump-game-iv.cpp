class Solution {
public:
    int minJumps(vector<int>& v) {
      int n = v.size(), ans = 0;
      unordered_map<int, vector<int>> um;
      for(int i = 0; i < n; i++)
        um[v[i]].emplace_back(i);
      vector<bool> vis(n, false);
      vis[0] = true;
      queue<int> q;
      q.emplace(0);
      while(!q.empty()){
        int sz = q.size();
        for(int k = 0; k < sz; k++){
          auto top = q.front(); q.pop();
          if(top == n - 1) return ans;
          vector<int> &temp = um[v[top]];
          temp.emplace_back(top - 1);
          temp.emplace_back(top + 1);
          for(auto &i: temp){
            if(i >= 0 and i < n and !vis[i]){
              vis[i] = true;
              q.emplace(i);
            }
          }
          temp.clear();
        }
        ans++;
      }
      return 0;
    }
};