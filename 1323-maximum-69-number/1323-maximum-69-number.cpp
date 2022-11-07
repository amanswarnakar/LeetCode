class Solution {
public:
    int maximum69Number (int num) {
      int cnt = -1, temp = 0, x = num;
      while(x){
        if(x % 10 == 6)
          cnt = temp;
        temp++;
        x /= 10;
      }
      if(cnt == -1) return num;
      return num + 3 * pow(10, cnt);
    }
};