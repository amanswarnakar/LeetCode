class Solution {
public:
    string pushDominoes(string d) {
      // .L.R...LR..L..
      // LL.RR.LLRRLL..
      string ans;
      int n = d.size();
      vector<int> rd(n, n+1), ld(n, n+1);
      int fl{}, fr{};
      for(int i = 0; i < n; i++){
        if(d[i] == 'R'){
          fr = i; break;
        }
      }
      for(int i = n-1; i >= 0; i--){
        if(d[i] == 'L'){
          fl = i; break;
        }
      }
      for(int i = 0; i < n; i++){
        if(d[i] == 'R'){
          // fr = i; 
          rd[i] = 0;
        }
        
        else if(d[i] == 'L')
          rd[i] = n+1;
        else if(d[i] == '.' and i > fr) 
          rd[i] = min(rd[i-1] + 1, n+1);
      }
      for(int i = n - 1; i >= 0; i--){
        if(d[i] == 'L'){ 
          ld[i] = 0;
          // fl = i;
        }
        else if(d[i] == 'R')
          ld[i] = n+1;
        else if(d[i] == '.' and i < fl)
          ld[i] = min(ld[i+1] + 1, n+1);
      }
      // for(auto i = 0; i < n; i++){
        // cout<<ld[i]<<" "<<rd[i]<<endl;
      // }
      for(int i = 0; i < n; i++){
        if(d[i] != '.') ans += d[i];
        else {
          // if(rd[i] == ld[i]) ans += '.';
          if(ld[i] < rd[i]) ans += 'L';
          else if(ld[i] > rd[i]) ans += 'R';
          else ans += '.';
            
        }
      }
      return ans;
    }
};