class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
      int n = v.size();
      for(int i = n - 2; i >= 0; i--){
        for(int j = i; j >= 0; j--){
          v[i][j] += min(v[i + 1][j], v[i + 1][j + 1]);
        }
      }
      // for(auto i: v){
        // for(auto j: i) cout<<j<<" ";
        // cout<<endl; 
      // }
      return v[0][0];
    }
};