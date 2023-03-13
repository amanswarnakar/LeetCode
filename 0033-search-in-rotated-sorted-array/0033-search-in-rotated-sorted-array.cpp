class Solution {
public:
    int search(vector<int>& v, int target) {
      int n = v.size(), l = 0, r = n - 1;
      bool lp = false; // leftPortion
      while(l <= r){
        int mid = l + (r - l) / 2;
        lp = v[mid] >= v[0] and v[mid] > v[n - 1];
        if(v[mid] == target) return mid;
        if(v[mid] < target and lp)
          l = mid + 1;
        else if(v[mid] > target and lp) {
          if(v[l] <= target) r = mid - 1;
          else l = mid + 1;
        } else if(v[mid] < target and !lp) {
          if(v[r] < target) r = mid - 1; 
          else l = mid + 1;
        } else if(v[mid] > target and !lp) r = mid - 1;
      }
      return -1;
    }
};