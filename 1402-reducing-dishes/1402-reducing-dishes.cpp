class Solution {
public:
    int recur(int idx, vector<int> &v){
      int k = 1, res = 0;
      for(int i = idx; i < v.size(); i++, k++)
        res += v[i] * k;
      return res;
    }
    int maxSatisfaction(vector<int>& v) {
      sort(begin(v), end(v));
      int n = v.size(), ans = INT_MIN;
      for(int i = 0; i < n; i++){
        ans = max(ans, recur(i, v));
      }
      return max(ans, 0);
    }
};