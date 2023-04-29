static class DSU {
  vector<int> Parent, Rank;
public:
  DSU(int n) {
    Parent.resize(n);
    Rank.resize(n, 0);
    for(int i = 0; i < n; i++) Parent[i] = i;
  }
  int Find(int x){
    return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
  }
  bool Union(int x, int y){
    int xset = Find(x), yset = Find(y);
    if(x != y){
      Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
      Rank[xset] += Rank[xset] == Rank[yset];
      return true;
    }
    return false;
  }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& graph, vector<vector<int>>& queries) {
      DSU dsu(n);
      for(int i=0;i<queries.size();i++)
        queries[i].push_back(i);
      sort(graph.begin(), graph.end(), [](auto &a, auto &b){ return a[2] < b[2]; });
      sort(queries.begin(), queries.end(), [](auto &a, auto &b){ return a[2] < b[2]; });
      int i = 0;
      vector<bool> ans(queries.size());
      for(auto &q: queries){
        while(i < graph.size() and graph[i][2] < q[2])
          dsu.Union(graph[i][0], graph[i++][1]);
        ans[q[3]] = dsu.Find(q[0]) == dsu.Find(q[1]);
      }
      return ans;
    }
};