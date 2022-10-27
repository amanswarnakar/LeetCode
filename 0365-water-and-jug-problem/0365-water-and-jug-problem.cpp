class Solution {
public:
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
};