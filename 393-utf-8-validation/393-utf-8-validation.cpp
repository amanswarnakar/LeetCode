class Solution {
public:
    int helper(int x){
      int y = 128, ans = 0;
      for(int i = 0; i < 5; i++) {
        if(x & y) {
          ans++; 
          y /= 2;
        } else {
          return ans;
        }
      }
      return ans;
    }
    bool validUtf8(vector<int>& data) {
      int i = 0, n = data.size();
      while(i < n) {
        int x = data[i];
        int m = helper(x);
        cout<<m<<" ";
        m--;
        if(m == 0 or m == 4) return false;
        if(m == -1) i++;
        else{
          while(m--) {
            i++;
            if(i >= n) return false;
            int num = data[i];
            if(helper(num) == 1) {
              continue;
            } else {
              return false;
            }
          }
          i++;
        }
      }
      return true;
    }
};