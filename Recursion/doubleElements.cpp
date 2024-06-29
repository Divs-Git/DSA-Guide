#include<bits/stdc++.h>
using namespace std;

void solve(int arr[],int n,int idx) {
  if(idx > n - 1) {
    return;
  } 
  arr[idx] *= 2;
  solve(arr,n,++idx);
}

int main() {
  int arr[] = {1,2,3,4,5,6};
  solve(arr,6,0);
  for(int el: arr) {
    cout <<el <<" ";
  }
  return 0;
}