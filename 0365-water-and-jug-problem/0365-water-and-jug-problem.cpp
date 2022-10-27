class Solution {
public:
  //  DFS
  
    bool dfs(int a, int b, int t, int curr, vector<bool> &vis, vector<int> &steps){
      if(curr < 0 or curr > a + b or vis[curr]) return false;
      vis[curr] = true;      
      bool ans = false;
      if(curr == t) return true;
      for(int i = 0; i < 4; i++){
        ans = ans or dfs(a, b, t, curr + steps[i], vis, steps);
      }
      return ans;
    }
    bool canMeasureWater(int a, int b, int t) {
      int maxi = a + b;
      vector<int> steps = {a, b, -a, -b};
      vector<bool> vis(maxi + 1, false);
      return dfs(a, b, t, 0, vis, steps);
    }
  
  
  /*    // BFS
  
    bool canMeasureWater(int a, int b, int t) {
      int maxi = a + b;
      int step[4] = {a, b, -a, -b};
      vector<bool> vis(maxi, false);
      queue<int> q;
      q.push(0);
      while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == t) return true;
        vis[node] = true;
        for(int i = 0; i < 4; i++){
          int newNode = node + step[i];
          if(newNode >= 0 and newNode <= maxi and !vis[newNode])
            q.push(newNode);
        }
      }
      return false;
    }
  */
};