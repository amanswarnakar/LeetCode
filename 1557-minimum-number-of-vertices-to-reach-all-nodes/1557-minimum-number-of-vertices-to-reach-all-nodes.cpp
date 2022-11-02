class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      vector<int> v(n, 0), ans;
      for(auto &edge: edges) v[edge[1]]++;
      for(int i = 0; i < v.size(); i++)
        if(!v[i]) ans.emplace_back(i);
      return ans;
    }
};