#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> optimal_summands(ll n) {
  vector<ll> summands;
  //write your code here
  ll x = double(-1.0+sqrt(1+(8*n)))/2.0;

  ll sum=0;
  for(ll i=1;i<x;i++){
    summands.push_back(i);
    sum += i;
  }
  summands.push_back(n-sum);

  return summands;
}

int main() {
  ll n;
  std::cin >> n;
  vector<ll> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  cout<<"\n";
}
