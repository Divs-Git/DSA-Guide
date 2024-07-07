// https://www.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int n = arr.size();
        int temp = arr[n-1];
        
        
        for(int i = n - 1 ; i >= 1 ; i--) {
            arr[i] = arr[i-1];
        }
        
        arr[0] = temp;
    }
};
