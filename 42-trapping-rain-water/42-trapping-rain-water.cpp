class Solution {
public:
    int trap(vector<int>& height) {
      // TC - O(3N)  SC - O(2N)
      int n = height.size();
      vector<int> left(n, height[0]), right(n, height[n-1]);
      for(int i = 1; i < n; i++){
        left[i] = max(left[i-1], height[i]);
      }
      for(int i = n-2; i >= 0; i--){
        right[i] = max(right[i+1], height[i]);
      }
      int ans = 0;
      for(int i = 1; i < n-1; i++){
        if(height[i] <= left[i] and height[i] <= right[i]){
          ans += min(left[i], right[i]) - height[i];
        }
      }
      return ans;
    }
};