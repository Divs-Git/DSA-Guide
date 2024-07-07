// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int i = 0;
        int j = 0;
        int n = arr.size();
        
        for(int j = 0 ; j < n ; ++j) {
            if(arr[j] == 0) {
                swap(arr[i],arr[j]);
                i++;
            }
        }
    }
};