class Solution {
public:
    string convert(string s, int m) {
      if(m == 1 or s.size() == 1) return s;
      int n = ceil(s.size() / (2 * m - 2.0));
      vector<vector<char>> v(m, vector<char>(n * m - n, ' '));
      int i = 0, j = 0, k = 0;
      string ans = "";
      while(k < s.size()){
        while(i < m and k < s.size()){
          v[i++][j] = s[k++];
        }
        i -= 2;
        j++;
        while(i > 0 and j < n * m - n and k < s.size()){
          v[i--][j++] = s[k++];
        }
      }
      for(auto &i: v){
        for(auto &j: i){
          // cout<<j<<" ";
          if(j != ' ') ans += j;
        }
        // cout<<endl;
      }
      return ans;
    }
};