#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;

//     long long current = 0;
//     long long next  = 1;

//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }

//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }

//     return sum % 10;
// }

ll get_fibonacci_partial_sum_efficient(ll from, ll to) {
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

    ll sum=0;
    if(from/60 == to/60){
        for(ll i=(from%60);i<=(to%60);i++){
            sum=(sum+pisano[i])%10;
        }
    }else {
        for(ll i=0;i<60;i++){
            if(i<=(to%60)){
                sum=(sum+pisano[i])%10;
            }
            if(i>=(from%60)){
                sum=(sum+pisano[i])%10;
            }
        }
    }
    return sum%10;
}

int main() {
    ll from, to;
    cin >> from >> to;
    // get_fibonacci_partial_sum_efficient(from, to);
    cout << get_fibonacci_partial_sum_efficient(from, to) << '\n';
    // std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
