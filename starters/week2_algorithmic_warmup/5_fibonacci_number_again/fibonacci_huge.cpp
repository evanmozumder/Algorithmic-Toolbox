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

ll get_fibonacci_huge_efficient(ll n, ll m){
    if (n <= 1)
        return n;

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
    // cout<<pisano[index]<<"\n";
    return pisano[index];
    // for(int i=0;i<pisano.size();i++){
    //     cout<<pisano[i]<<" ";
    // }
    // cout<<endl;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << get_fibonacci_huge_efficient(n, m) << '\n';
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    // get_fibonacci_huge_efficient(n,m);
}
