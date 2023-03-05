class Solution {
public:
    int minJumps(vector<int>& arr) {
      int n = arr.size();
      unordered_map<int, vector<int>> um;
      for (int i = 0; i < n; i++)
        um[arr[i]].push_back(i);
      vector<bool> vis(n); vis[0] = true;
      queue<int> q; q.push(0);
      int ans = 0;
      while (!q.empty()) {
        for (int size = q.size(); size > 0; --size) {
          int i = q.front(); q.pop();
          if (i == n - 1) return ans; 
          vector<int>& temp = um[arr[i]];
          temp.push_back(i - 1); 
          temp.push_back(i + 1);
          for (int j : temp) {
            if (j >= 0 && j < n && !vis[j]) {
              vis[j] = true;
              q.push(j);
            }
          }
          temp.clear(); 
        }
        ans++;
      }
      return 0; 
    }
};