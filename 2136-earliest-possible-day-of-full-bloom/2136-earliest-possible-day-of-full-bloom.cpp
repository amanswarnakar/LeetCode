class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
      if(a.first > b.first) return true;
      else if(a.first == b.first) return a.second > b.second;
      return false;
    }
    
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
      int n = p.size(), ans = 0, temp = 0;
      vector<pair<int, int>> v(n);
      for(int i = 0; i < n; i++){
        v.emplace_back(g[i], p[i]);
      }
      sort(begin(v), end(v), comp); // Sorting Descendingly wrt grow time
      for(auto &p: v){
        temp += p.second;
        ans = max(ans, temp + p.first);
      }
      return ans;

      // int n = p.size(), ans = 0, temp = 0;
      // vector<vector<int>> v(n, vector<int>(2, 0));
      // for(int i = 0; i < n; i++){
        // v[i][0] = g[i];
        // v[i][1] = p[i];
      // }
      // sort(begin(v), end(v), greater<>());  
      // for(int i = 0; i < n; i++){
      //   temp += v[i][1];
      //   ans = max(ans, temp + v[i][0]);
      // }
      // return ans;
    }
};