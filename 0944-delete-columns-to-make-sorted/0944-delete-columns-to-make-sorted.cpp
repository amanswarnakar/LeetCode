class Solution {
public:
    int minDeletionSize(vector<string>& v) {
      int n = v.size(), l = v[0].size(), ans = 0;
      for(int i = 0; i < l; i++){
        for(int j = 0; j < n - 1; j++){
          if(v[j][i] > v[j + 1][i]){
            ans++; break;
          }
        }
      }
      return ans;
    }
};