#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int idx,int target) {
  if(idx > n -1) {
    return -1;
  }

  if(arr[idx] == target) {
    return idx;
  }

  return solve(arr,n,++idx,target);
}

void findOcuurance(int arr[],int n,int idx,int target) {
   if(idx > n -1) {
    cout << -1 <<endl;
    return;
  }

  if(arr[idx] == target) {
    cout <<idx <<" ";
  }

  findOcuurance(arr,n,++idx,target);
}

int main() {
  int arr[] = {1,2,5,4,5};
  int target = 6;
  cout <<solve(arr,5,0,target) <<endl;
  findOcuurance(arr,5,0,target);

  return 0;
}