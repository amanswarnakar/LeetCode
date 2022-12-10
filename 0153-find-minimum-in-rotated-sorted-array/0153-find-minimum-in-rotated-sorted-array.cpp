class Solution {
public:
    int findMin(vector<int>& v) {
      // Binary Search Approach - TC - O(logN)
      sort(v.begin(), v.end());
      return v[0];
      
      
      // TC - O(N)
      
      // for(int i = 0; i < v.size() - 1; i++){
      //   if(v[i] > v[i + 1]) return v[i + 1];
      // }
      // return v[0];
    }
};