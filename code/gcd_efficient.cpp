#include<bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2){
  int m=max(n1,n2);
  int mi=min(n1,n2);
  m=m%mi;
  if(m==0)
    return mi;
  return gcd(m,mi);
}

void solve() {
  int num1,num2;
  cin >> num1 >> num2;
  cout << gcd(num1,num2) << endl;
}

int main() {
  int t=1;
//  cin >> t;
  while(t--){
    solve();
  }
}
