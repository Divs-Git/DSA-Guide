#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &v,int n,int idx,int ans) {
  if(idx > n - 1) {
    return ans;
  }

  ans =  ans*10 + v[idx] % 10;
  return solve(v,n,++idx,ans);

}

int main() {
  vector<int> v = {1,2,3,4,2};
  int ans = 0;
  cout <<solve(v,v.size(),0,ans);

  return 0;
}