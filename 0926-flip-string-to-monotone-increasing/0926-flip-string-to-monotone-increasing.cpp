class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int cnt1 = 0, ans = 0;
      for(char &c: s){
        if(c == '1') cnt1++;
        else ans = min(++ans, cnt1);
        // cout<<cnt1<<" "<<ans<<endl;
      }
      return ans;
    }
};