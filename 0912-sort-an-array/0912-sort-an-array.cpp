class Solution {
public:
    void merge(vector<int> &v, int l, int mid, int r, vector<int> &temp){
      int s1 = l, s2 = mid + 1, e1 = mid - l + 1, e2 = r - mid;
      for(int i = 0; i < e1; i++){
        temp[s1 + i] = v[s1 + i];
      }
      for(int i = 0; i < e2; i++){
        temp[s2 + i] = v[s2 + i];
      }
      int i = 0, j = 0, k = l;
      while(i < e1 and j < e2){
        if(temp[s1 + i] <= temp[s2 + j]){
          v[k++] = temp[s1 + i];
          i++;
        } else {
          v[k++] = temp[s2 + j];
          j++;
        }
      }
      while(i < e1){
        v[k++] = temp[s1 + i++];
      }
      while(j < e2){
        v[k++] = temp[s2 + j++];
      }
    }
    void mergeSort(vector<int> &v, vector<int> &temp, int l, int r){
      if(l >= r) return;
      int mid = l + (r - l) / 2;
      mergeSort(v, temp, l, mid);
      mergeSort(v, temp, mid + 1, r);
      merge(v, l, mid, r, temp);
    }
    vector<int> sortArray(vector<int>& nums) {
      int n = nums.size();
      vector<int> temp(n, 0);
      mergeSort(nums, temp, 0, n - 1);
      return nums;
    }
};