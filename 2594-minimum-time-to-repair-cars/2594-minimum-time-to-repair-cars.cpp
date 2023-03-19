class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
      long long l = 0, r = 1e14;
      while(l < r){
        long long mid = l + (r - l) / 2, cnt = 0;
        for(auto &i: ranks){
          cnt += (int)sqrt(mid / i);
        }
        if(cnt < cars) l = mid + 1;
        else r = mid;
      }
      return l;
    }
};