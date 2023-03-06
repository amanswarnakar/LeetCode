class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
      int l = 0, r = v.size();
      while(l < r){
        int mid = l + (r - l) / 2;
        if(v[mid] - (mid + 1) >= k) r = mid;
        else l = mid + 1;
      }
      return l + k;
      
      // int n = v.size();
      // for(int i = 0; i < n; i++){
      //   int diff = v[i] - (i + 1);
      //   if(diff >= k) return i + k;
      // }
      // return n + k;
    }
};