class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
      sort(v.begin(), v.end());
      int n = v.size(), l = 1, r = v[n - 1], ans = 0;
      while(l <= r){
        int mid = l + (r - l) / 2;
        long long int cnt = 0;
        for(int i = 0; i < n; i++){
          if(v[i] < mid) cnt++;
          else cnt += (v[i] - 1) / mid + 1;
        }
        if(cnt > h) l = mid + 1;
        else r = mid - 1;
      }
      return l;
    }
};