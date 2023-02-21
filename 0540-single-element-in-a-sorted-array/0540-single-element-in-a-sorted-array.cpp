class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
      int l = 0, r = v.size() - 1;
      while(l < r){
        int mid = l + (r - l) / 2;
        if(v[mid] == v[mid ^ 1]) l = mid + 1;
        else r = mid;
      }
      return v[l];
    }
};