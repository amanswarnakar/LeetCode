class Solution {
public:
    int countDaysTogether(string aA, string lA, string aB, string lB) {
      int aa = 0, la = 0, ab = 0, lb = 0, ans = 0;
      int v[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      // cout<<aA[0]<<" "<<aA[1]<<endl;
      // cout<<int(aA[0] - '0') * 10 + int(aA[1] - '0');
      for(int i = 0; i < int(aA[0] - '0') * 10 + int(aA[1] - '1'); i++){
        // cout<<i;
        aa += v[i];
      }
      aa += int(aA[3] - '0') * 10 + int(aA[4] - '0');
      
      
      
      for(int i = 0; i < int(lA[0] - '0') * 10 + int(lA[1] - '1'); i++){
        // cout<<i;
        la += v[i];
      }
      la += int(lA[3] - '0') * 10 + int(lA[4] - '0');
      
      
      
      for(int i = 0; i < int(aB[0] - '0') * 10 + int(aB[1] - '1'); i++){
        // cout<<i;
        ab += v[i];
      }
      ab += int(aB[3] - '0') * 10 + int(aB[4] - '0');
      
      
      
      for(int i = 0; i < int(lB[0] - '0') * 10 + int(lB[1] - '1'); i++){
        // cout<<i;
        lb += v[i];
      }
      lb += int(lB[3] - '0') * 10 + int(lB[4] - '0');
      // cout<<endl;
      // cout<<aa<<endl<<la<<endl<<ab<<endl<<lb;
      if(aa < ab){
        if(la < lb){
          ans = la - ab + 1 > 0 ? la - ab + 1 : 0 ;
        } else {
          ans = lb - ab + 1 > 0 ? lb - ab + 1 : 0;
        }
      } else {
        if(la > lb)
          ans = lb - aa + 1 > 0 ? lb - aa + 1 : 0;
        else
          ans = la - aa + 1 > 0 ? la - aa + 1 : 0;
      }
      return ans;
    }
};