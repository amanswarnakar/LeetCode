class Solution {
public:
    vector<int> answerQueries(vector<int>& v, vector<int>& q) {
      int n = v.size();
      sort(v.begin(), v.end());
      vector<int> ans, psum(n, v[0]);
      for(int i = 1; i < n; i++){
        psum[i] = psum[i - 1] + v[i]; 
      }
      for(auto &k: q){
        ans.emplace_back(upper_bound(psum.begin(), psum.end(), k) - psum.begin());
      }
      return ans;
    }
};