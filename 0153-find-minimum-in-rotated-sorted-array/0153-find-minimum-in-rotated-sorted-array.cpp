class Solution {
public:
    int findMin(vector<int>& v) {
      // Binary Search Approach - TC - O(logN)
      int l = 0, r = v.size() - 1;
      if(v.size() == 1 or v[r] > v[l]) return v[0];
      while(l < r and v[l] > v[r]){
        int mid = l + (r -  l) / 2;
        if(v[mid] >= v[0]) l = mid + 1;
        else r = mid;
      }
      return v[l];
      
      
      // TC - O(N)
      
      // for(int i = 0; i < v.size() - 1; i++){
      //   if(v[i] > v[i + 1]) return v[i + 1];
      // }
      // return v[0];
    }
};