class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
      sort(p.begin(), p.end());
      sort(t.begin(), t.end());
      int x = p.size() - 1, y = t.size() - 1;
      int ans = 0;
      while(x >= 0 and y >= 0) {
        if(p[x] <= t[y]){
          ans++; x--; y--;
        } else {
          x--;
        }
      }
      return ans;
    }
};