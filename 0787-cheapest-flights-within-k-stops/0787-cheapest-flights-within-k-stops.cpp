class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int, int>>> graph(n);
      for(auto &f: flights){
        graph[f[0]].push_back({f[1], f[2]});
      }
      vector<int> minCost(n, INT_MAX);
      int stops = 0;
      queue<pair<int, int>> q;
      q.push({src, 0});
      while(!q.empty() and stops <= k){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
          auto [node, price] = q.front(); q.pop();
          for(auto &[adj, cost]: graph[node]){
            if(price + cost < minCost[adj]){
              minCost[adj] = cost + price;
              q.push({adj, minCost[adj]});
            }
          }
        }
        stops++;
      }
      return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};