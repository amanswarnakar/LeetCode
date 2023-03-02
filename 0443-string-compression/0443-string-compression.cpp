class Solution {
public:
    int compress(vector<char>& c) {
      int n = c.size(), i = 0, ans = 0;
      while(i < n){
        int len = 1;
        while(i + len < n and c[i + len] == c[i]) len++;
        c[ans++] = c[i];
        if(len > 1){
          for(auto &j: to_string(len)){
            c[ans++] = j;
          }
        }
        i += len;
      }
      return ans;
    }
};