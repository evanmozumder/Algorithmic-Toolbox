#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % m;
// }

void get_fibonacci_huge_efficient(ll n,ll m){

  ll fibo[n+1];
  ll sq_sum=0;
  for(ll i=0;i<n+1;i++){
    if(i<2)fibo[i]=i;
    else fibo[i]=fibo[i-1]+fibo[i-2];
    sq_sum+=(fibo[i]*fibo[i]);
  }
  // if (n <= 1)
  //     return n;

  ll previous = 0;
  ll current  = 1;
  vector<ll>pisano;
  pisano.push_back(0);
  pisano.push_back(1);
  while(true){
    ll tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current)%m;
    if(current==1 && previous==0)break;
    pisano.push_back(current);
  }
  pisano.pop_back();
  ll index = n%pisano.size();
  cout<<pisano.size()<<"\n";
  // return pisano[index];
  ll sum=0,sum_nth=0;
  for(int i=0;i<pisano.size();i++){
    cout<<pisano[i]<<" ";
    sum+=pisano[i];
    if(i<=(n%pisano.size()))sum_nth+=(pisano[i]*pisano[i]);
  }
  cout<<endl;
  cout<<sq_sum<<" "<<sum_nth<<" "<<sum<<endl;
  // cout<<sum_nth<<endl;
}

int main() {
  ll n, m;
  cin >> n >> m;
  // cout << get_fibonacci_huge_efficient(n, m) << '\n';
  // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
  get_fibonacci_huge_efficient(n,m);
}
