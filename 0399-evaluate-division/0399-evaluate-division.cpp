class Solution {
public:
    void dfs(string node, string dest, map<string, vector<string>> &graph, map<string, double> &um, map<string, int> &vis, bool &found, double &res){
      vis[node] = 1;
      if(found) return;
      for(auto &adj: graph[node]){
        if(vis[adj] != 1){
          res *= um[node + "#" + adj];
          if(adj == dest){
            found = true; return;
          }
          dfs(adj, dest, graph, um, vis, found, res);
          if(found) return;
          else res /= um[node + "#" + adj];
        }
      }
    }
  
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
      vector<double> ans;
      map<string, double> um;
      map<string, vector<string>> graph;
      for(int i = 0; i < eq.size(); i++){
        string u = eq[i][0], v = eq[i][1];
        um[u + "#" + v] = val[i];
        um[v + "#" + u] = 1 / val[i];
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
      }
      for(auto &i: q){
        string s = i[0], e = i[1];
        if(graph.find(s) == graph.end() or graph.find(e) == graph.end()) {
          ans.emplace_back(-1);
        } else {
          double res = 1;
          bool found = false;
          map<string, int> vis;
          if(s == e) found = true;
          else dfs(s, e, graph, um, vis, found, res);
          if(found) ans.emplace_back(res);
          else ans.emplace_back(-1);
        }
      }
      return ans;
    }
};