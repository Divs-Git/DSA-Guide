#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,int idx,vector<int> &v) {
  if(idx > n - 1) {
    return;
  }
  if(!(arr[idx] & 1)) {
    v.push_back(arr[idx]);
  }

  solve(arr,n,++idx,v);
}


int main() {
  int arr[] = {1,3,4,2,6,7,9};
  vector<int> v;
  solve(arr,7,0,v);

  for(auto el: v) {
    cout <<el <<" ";
  }
  return 0;
}