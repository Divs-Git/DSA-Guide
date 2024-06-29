#include<bits/stdc++.h>
using namespace std;

void maxElement(int arr[],int n,int &maxi,int idx) {
  if(idx > n - 1) {
    return;
  }

  maxi = max(maxi,arr[idx]);
  maxElement(arr,n,maxi,++idx);

}

int main() {
  int arr[] = {1,3,4,2,6,7,9};
  int maxi = INT_MIN;

  maxElement(arr,7,maxi,0);
  cout <<maxi <<endl;
  return 0;
}