#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void solve() {
	ll n;
	cin >> n;
	ll a[n];
	a[0]=0,a[1]=1;
	cout << a[0] << " " << a[1] << " ";
	for(int i=2;i<n;++i){
		a[i]=a[i-1]+a[i-2];
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int t=1;
	cin >> t;
	while(t--)
		solve();

}
