#include<bits/stdc++.h>
using namespace std;

void minElement(int arr[],int n,int &mini,int idx) {
  if(idx > n - 1) {
    return;
  }

  mini = min(mini,arr[idx]);
  minElement(arr,n,mini,++idx);

}

int main() {
  int arr[] = {1,3,4,2,6,7,9};
  int mini = INT_MAX;

  minElement(arr,7,mini,0);
  cout <<mini <<endl;
  return 0;
}