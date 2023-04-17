class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& v, int k) {
      int maxx = *max_element(v.begin(), v.end());
      vector<bool> ans(v.size(), false);
      for(int i = 0; i < v.size(); i++){
        if(v[i] + k >= maxx) ans[i] = true;
      }
      return ans;
    }
};