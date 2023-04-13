#include <iostream>
using namespace std;
#define ll long long
const long long M= 1000000007;

// int get_fibonacci_last_digit_naive(int n) {
//     if (n <= 1)
//         return n;

//     int previous = 0;
//     int current  = 1;

//     for (int i = 0; i < n - 1; ++i) {
//         int tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % 10;
// }

ll fibonacci_fast(ll n) {
    ll fibo[n+1];
    for(ll i=0;i<n+1;i++){
        if(i<2)fibo[i]=i;
        else fibo[i]=((fibo[i-1]%10)+(fibo[i-2]%10))%10;
    }

    return fibo[n]%10;
}

int main() {
    ll n;
    cin >> n;
    // int c = get_fibonacci_last_digit_naive(n);
    // std::cout << c << '\n';
    cout<<fibonacci_fast(n)<<"\n";
    }
