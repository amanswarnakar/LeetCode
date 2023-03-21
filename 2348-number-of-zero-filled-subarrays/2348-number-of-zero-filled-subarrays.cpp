class Solution {
public:
    long long zeroFilledSubarray(vector<int>& v) {
      long long int ans = 0, cnt = 0, n = v.size();
      for(int i = 0; i < n; i++){
        if(!v[i]){
          cnt++;
          ans += cnt;
        } else cnt = 0;
      }
      return ans;
    }
};