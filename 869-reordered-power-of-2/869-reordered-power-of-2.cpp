class Solution {
public:
    vector<int> count(int n){
      vector<int> arr(10, 0);
      while(n){
        arr[n%10]++;
        n /= 10;
      }
      return arr;
    }
    bool compareArray(vector<int> a, vector<int> b){
      if(a.size() != b.size())  return false;
      for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i])  return false;
      }
      return true;
    }
    bool reorderedPowerOf2(int n) {
      vector<int> arr = count(n);
      long long int num = 1;
      for(int i = 0; i < 31; i++){
        if(compareArray(arr, count(num))) return true;
        num *= 2;
      }
      return false;
    }
};