class Solution {
public:
   bool isPossible(vector<int> &v, long long time, long long t){
      long long res = 0;
      for(int i = 0; i < v.size(); i++){
        res += time / v[i];
        if(res >= t) return true;
      }
      return false;
    }
    long long minimumTime(vector<int>& v, int t) {
      long long int l = 1, r = 1LL * *min_element(begin(v), end(v)) * t;
      while(l < r){
        long long mid = l + (r - l) / 2;
        if(isPossible(v, mid, t)) r = mid;
        else l = mid + 1;
      }
      return l;
    }
};