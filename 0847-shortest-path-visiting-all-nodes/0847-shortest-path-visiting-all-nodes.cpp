class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
      int n = graph.size();
      if(n == 1) return 0;
      int all = (1 << n) - 1; // for n == 5, all = 100000 - 1 = 11111
      queue<pair<int, pair<int, int>>> q;
      set<pair<int, int>> vis;
      for(int i = 0; i < n; i++){
        int mask = 1 << i;
        // q.emplace(pair<int, pair<int, int>>{i, pair<int, int>{0, mask}});
        q.push({i, {0, mask}});
        vis.insert({i, mask});
      }
      while(!q.empty()){
        auto top = q.front();
        q.pop();  
        int currNode = top.first, dist = top.second.first, mask = top.second.second;
        for(auto &node: graph[currNode]){
          int newMask = mask | (1 << node);
          if(newMask == all) return dist + 1;
          if(vis.count({node, newMask}))
            continue;
          else {
            // q.emplace(pair<int, pair<int, int>>{node, pair<int, int>{dist + 1, newMask}});
            q.push({node, {dist + 1, newMask}});
            vis.insert({node, newMask});
          }
        }
      }
      return 0;
    }
};