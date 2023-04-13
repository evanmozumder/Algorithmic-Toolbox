#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// int fibonacci_sum_squares_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current * current;
//     }

//     return sum % 10;
// }

ll fibonacci_sum_squares_fast(ll n){
    ll sum=0;
    
    ll previous = 0,current=1;
    vector<ll>pisano;
    pisano.push_back(0);
    pisano.push_back(1);
    while(true){
        ll tmp_previous = previous;
        previous = current;
        current = (tmp_previous+current)%10;
        if(current==1 && previous==0)break;
        pisano.push_back(current);
    }
    pisano.pop_back();
    for(ll i=0;i<=(n%60);i++){
        sum+=(pisano[i]*pisano[i]);
    }

    return sum%10;
}

int main() {
    ll n = 0;
    std::cin >> n;
    // std::cout << fibonacci_sum_squares_naive(n)<<"\n";
    std::cout << fibonacci_sum_squares_fast(n)<<"\n";
}
