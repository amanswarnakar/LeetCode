class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
      sort(v.begin(), v.end());
      int ans = 1, n = v.size(), temp = v[0][1];
      for(int i = 1; i < n; i++){
        if(v[i][0] > temp){
          ans++; temp = v[i][1]; 
        }
        temp = min(temp, v[i][1]);
      }
      return ans;
    }
};