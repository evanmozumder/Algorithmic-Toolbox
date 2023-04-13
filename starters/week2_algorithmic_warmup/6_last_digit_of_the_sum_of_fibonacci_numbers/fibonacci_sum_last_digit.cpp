#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// int fibonacci_sum_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current;
//     }

//     return sum % 10;
// }
ll fibonacci_sum_fast(ll n) {
    ll previous = 0;
  ll current  = 1;
  vector<ll>pisano;
  pisano.push_back(0);
  pisano.push_back(1);
  while(true){
    ll tmp_previous = previous;
    previous = current;
    current = (tmp_previous + current)%10;
    if(current==1 && previous==0)break;
    pisano.push_back(current);
  }
  pisano.pop_back();
//   ll index = n%pisano.size();
//   cout<<pisano.size()<<"\n";
  // return pisano[index];
  ll sum=0,sum_nth=0;
  for(int i=0;i<pisano.size();i++){
    // cout<<pisano[i]<<" ";
    // sum+=pisano[i];
    if(i<=(n%pisano.size())){
        sum_nth+=pisano[i];
    }else {
        break;
    }
  }
//   cout<<endl;
  // cout<<fib_sum<<" "<<sum_nth<<" "<<sum<<endl;
//   cout<<sum_nth<<endl;
    return sum_nth%10;
}

int main() {
    long long n = 0;
    cin >> n;
    // std::cout << fibonacci_sum_naive(n)<<"\n";
    cout << fibonacci_sum_fast(n)<<"\n";
}
