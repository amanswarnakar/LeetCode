class Solution {
public:
    int jump(vector<int>& v) {
      int n = v.size(), ans = 0, end = 0, farthest = 0;
      for(int i = 0; i < n - 1; i++){
        farthest = max(farthest, i + v[i]);
        if(i == end){
          end = farthest; ans++;
        }
      }
      return ans;
    }
};