class Solution {
public:
    int shipWithinDays(vector<int>& v, int days) {
      int n = v.size(), l = 0, r = accumulate(v.begin(), v.end(), 0);
      for(auto &i: v) l = max(l, i);
      while(l < r){
        int mid = l + (r - l) / 2, cnt = 1, sum = 0;
        for(int i = 0; i < n and cnt <= days; sum += v[i++]){
          if(sum + v[i] > mid){
            cnt++; sum = 0;
          }
        }
        if(cnt > days) l = mid + 1;
        else r = mid;
      }
      return l;
    }
};