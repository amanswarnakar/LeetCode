class Solution {
public:
    int maxArea(vector<int>& v) {
      int l = 0, r = v.size() - 1;
      int ans = 0;
      while(l < r){
        int temp = min(v[l], v[r]);
        ans = max(ans, temp * (r - l));
        if(v[l] < v[r]) l++;
        else r--;
      }
      return ans;
    }
};