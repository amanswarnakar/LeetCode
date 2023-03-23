class Solution {
public:
    bool isPossible(vector<int> &v, int mid, int h){
      long long int res = 0;
      for(auto &i: v){
        res += (i / mid) + (i % mid != 0);
        if(res > h) return false;
      }
      return true;
    }
    int minEatingSpeed(vector<int>& v, int h) {
      int l = 1, r = *max_element(begin(v), end(v));
      while(l <= r){
        int mid = l + (r - l) / 2;
        if(isPossible(v, mid, h)) r = mid - 1;
        else l = mid + 1;
      }
      return l;
    }
  
  /*
    long long int helper(vector<int> &v, int b){
      long long int res = 0, n = v.size();
      for(int i = 0; i < n; i++){
        res += (v[i] / b) + (v[i] % b != 0);
      }
      return res;
    }
    int minEatingSpeed(vector<int>& v, int h) {
      // sort(begin(v), end(v));
      long long int n = v.size(), noOfHours = 0;
      long long int l = 1, r = *max_element(begin(v), end(v));
      while(l <= r){
        int mid = l + (r - l) / 2;
        noOfHours = helper(v, mid);
        if(noOfHours <= h) r = mid - 1;
        else l = mid + 1;
      }
      return l;
    }
  */
};