class Solution {
public:
    bool isPossible(vector<int> &v, long long time, int t){
      long long res = 0;
      for(auto i: v){
        res += time / i;
      }
      return res >= t;
    }
    long long minimumTime(vector<int>& v, int t) {
      long long int l = 1;
      long long int r = 1LL * *min_element(v.begin(), v.end()) * t;
      while(l < r){
        long long mid = l + (r - l) / 2;
        if(isPossible(v, mid, t)) r = mid;
        else l = mid + 1;
      }
      return l;
    }
};