class Solution {
public:
  bool isPossible(vector<int> &v, int mid, int days){
    int n = v.size(), sum = 0, res = 1;
    for(int i = 0; i < n; i++){
      sum += v[i];
      if(sum > mid){
        res++; sum = v[i];
      }
      if(res > days) return false;
    }
    return true;
  }
  int shipWithinDays(vector<int>& v, int days) {
    int n = v.size(), l = 0, r = 0;
    for(auto &i: v){
      r += i;
      l = max(l, i);
    }
    while(l < r){
      int mid = l + (r - l) / 2;
      if(isPossible(v, mid, days)) r = mid;
      else l = mid + 1;
    }
    return l;
  }
};