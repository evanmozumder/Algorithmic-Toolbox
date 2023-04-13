#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// long long lcm_naive(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;

//   return (long long) a * b;
// }
// ll lcm(ll a,ll b){
//   if(a<b){
//     ll temp = a;
//     a=b;
//     b=temp;
//   }
//   ll lcm=a;
//   while(true){
//     if(lcm%a==0 && lcm%b==0)return lcm;
//     lcm++;
//   }
// }
ll gcd(ll x,ll y){
  ll a = max(x, y);
  ll b = min(x, y);
  if(b==0)return a;
  else 
    return gcd(b,(a%b));
}
ll lcm_efficient(ll a,ll b){
  return (a*b)/gcd(a,b);
}
int main() {
  ll a, b;
  cin >> a >> b;
  // std::cout << lcm_naive(a, b) << std::endl;
  // cout<<gcd(a,b)<<endl;
  // cout << lcm_efficient(a, b) << endl;
  cout<<lcm_efficient(a,b)<<endl;
  return 0;
}
